import fileinput
import re

import bigint

for line in fileinput.input():
    tokens = line.split()

    funcname = tokens[0]
    tokens.pop(0)
    f = bigint.opmap[funcname]

    nums = [int(x) for x in tokens]
    res = f(*nums)

    ls = [res, funcname]
    ls.extend(nums)    
    print(*ls)
