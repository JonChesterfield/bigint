local args = {...}
local mod = {}


if #args ~= 4 then
   print("Expect operation prefix inttype contexttype")
   for _, v in ipairs(args) do
      print(v)
   end
   os.exit(1)
end

-- do this
local operation = args[1]

-- prefix is the name of the specialisation, e.g. #include "prefix.h" makes sense
local prefix = args[2]
local inttype = args[3]
local contexttype = args[4]




local api_table = {
   {"abs", 1,},
   {"neg", 1,},
   {"incr", 1,},
   {"decr", 1,},
   
   {"add", 2,},
   {"sub", 2,},
   {"mul", 2,},
   {"div", 2,},
   {"rem", 2,},

   {"or", 2,},
   {"and", 2,},
   {"xor", 2,},

}




local arity = {}
for _, v in ipairs(api_table) do
   arity[v[1]] = v[2]
end


local inttype = "proto"
local contexttype = "proto_context"

local memory_prefix = 'memchk'


mod.memory_header = (function ()
      local r = string.format([[
#ifndef %s_MEMORY_CHECK_INCLUDED_H
#define %s_MEMORY_CHECK_INCLUDED_H

#include "%s.h"
]], prefix:upper(), prefix:upper(), prefix)


for _, row in ipairs(api_table) do
   local name = row[1]
   r = r .. string.format("\n%s %s_%s_%s(%s", inttype, prefix, memory_prefix, name, contexttype)
   for i = 1, arity[name] do
      r = r .. string.format(", %s", inttype)
   end
   r = r .. ");"
         
end

   r = r .. "\n\n#endif\n"

   return r
end)


mod.memory_source = (function ()
      local r = string.format([[
#include "%s_memory_check.h"
]], prefix)


for _, row in ipairs(api_table) do
   local name = row[1]
   r = r .. string.format("\n%s %s_%s_%s(%s context", inttype, prefix, memory_prefix, name, contexttype)
   for i = 1, arity[name] do
      r = r .. string.format(", %s arg%s", inttype, i-1)
   end
   r = r .. ")\n"

   local call = string.format("%s_%s(context", prefix, name)
   for i = 1, arity[name] do
      call = call .. string.format(", arg%s", i-1)
   end
   call = call .. ")"

   -- todo, generalise the other strings
   -- the off by one in the for loop is unfortunate, meant never catching
   -- the last memory allocation in the routine
   r = r .. string.format([[
{
   uint64_t initial_fuel = proto_context_fuel_value(context);
   uint64_t initial_count = proto_context_count_value(context);

   proto_context_set_fuel_value(context, UINT64_MAX);
   proto_context_set_count_value(context, 0);
   proto failure = proto_create_invalid();
   
   %s result = %s;

   if (%s_valid(context, result))
   {
     uint64_t used = proto_context_count_value(context);
     
     for (uint64_t allow = used/*-1*/; allow --> 0;)
     {
       proto_context_set_fuel_value(context, allow);     
       proto_context_set_count_value(context, 0);

       %s res = %s;

       bool succeeded = %s_valid(context, res);
       if (succeeded)
       {
         proto_destroy(context, res);
         proto_destroy(context, result);
         result = failure;
         break;
       }
     }
   }

   proto_context_set_fuel_value(context, initial_fuel);
   proto_context_set_count_value(context, initial_count);

   return result;
}
]], inttype, call, prefix, inttype, call, prefix)
   

end


   return r
end)




if mod[operation] then
   print(mod[operation]())
else
   print(string.format("Unknown operation %s", operation))
   os.exit(1)
end

