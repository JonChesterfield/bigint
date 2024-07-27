#!/usr/bin/gawk -f

function basename(file) {
    sub(".*/", "", file)
    return file
}

BEGIN {
    print "import unittest"
    print "import bigint"
    
    print "if __name__ == '__main__':"
    print "    unittest.main()"
    print ""

    printf ("class Test_%s_Function(unittest.TestCase):\n", basename(ARGV[1]))
    printf ("    def test_cases(self):\n")

    funcprefix="bigint.opmap['"
    funcsuffix="']"
}

{

    printf ("        self.assertEqual(%s, %s%s%s(%s", $1, funcprefix, $2, funcsuffix, $3)
    for (i = 3; i < NF; i++)
        printf(", %s", $(i+1))
    printf("))\n")   
}
