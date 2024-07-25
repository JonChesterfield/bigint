#!/usr/bin/gawk -f

function basename(file) {
    sub(".*/", "", file)
    return file
}

BEGIN {
    print "#include \"../vendor/EvilUnit/EvilUnit.h\""
    print "#include \"../proto_memory_check.h\""

    
    printf ("MODULE(test_memchk_%s)\n{\n", basename(ARGV[1]))
    printf ("  struct proto_context_ty context_state; \n")
    printf ("  proto_context ctx = &context_state;\n")
    printf ("  proto_context_init(ctx);\n")
    funcprefix="proto_memchk_"
}

{
    printf ("  {\n")
    printf ("    proto expect = proto_from_base10_cstr(ctx, \"%s\");\n", $1)
    for (i = 2; i < NF; i++)
        printf("    proto arg%s = proto_from_base10_cstr(ctx, \"%s\");\n", i-2, $(i+1))

    printf("    proto result = %s%s(ctx", funcprefix, $2)
    for (i = 2; i < NF; i++)
        printf(", arg%s", i-2)
    printf(");\n")   

    printf ("    CHECK(proto_equal(ctx, expect, result));\n")
    printf ("    proto_destroy(ctx, expect);\n")
    for (i = 2; i < NF; i++)
        printf("    proto_destroy(ctx, arg%s);\n", i-2, $(i+1))

    printf ("    proto_destroy(ctx, result);\n")

    printf("  }\n")   
}


END {
    printf("}\n");
}
