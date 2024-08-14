#!/usr/bin/gawk -f

function basename(file) {
    sub(".*/", "", file)
    return file
}

BEGIN {
    print "#include \"../vendor/EvilUnit/EvilUnit.h\""
    print "#include \"bigint.hpp\""
    print "#include \"simple.hpp\""
    print ""
    printf ("static bigint_simple simple_from_decimal(const char* str)\n{\n  return bigint::from_decimal<bigint_simple>(str, str + __builtin_strlen(str));\n}\n")
    print ""
    printf ("MODULE(test_%s)\n{\n", basename(ARGV[1]))

    
    funcprefix="bigint::"
}

{
    printf ("  {\n")
    printf ("    bigint_simple expect = simple_from_decimal(\"%s\");\n", $1)
    for (i = 2; i < NF; i++)
        printf("    bigint_simple arg%s = simple_from_decimal(\"%s\");\n", i-2, $(i+1))

    printf("    bigint_simple result = %s%s(", funcprefix, $2)
    sep = ""
    for (i = 2; i < NF; i++) {
        printf("%sarg%s", sep, i-2)
        sep = ", "
    }
    printf(");\n")   

    printf ("    CHECK(bigint::boolean_equal(expect, result));\n")
    printf ("    bigint::destroy(expect);\n")
    for (i = 2; i < NF; i++)
        printf("    bigint::destroy(arg%s);\n", i-2, $(i+1))

    printf ("    bigint::destroy(result);\n")

    printf("  }\n")   
}


END {
    printf("}\n");
}
