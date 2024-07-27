#!/usr/bin/gawk -f

# Takes a directory then N files
# handles permutations of control block and result
# writes everything into files in the current directory
# Does a top level division into control/ and simple/ based on
# whether the test case sets a control block, then writes the cases to
# files named for the operation. Any cases that are missing the result
# value go under expr_$op to distinguish from complete cases


BEGIN {
  DST=ARGV[1]
  ARGV[1] = ""
  print "Writing with base " DST

  mkvar_varname = "extract_files"
}



/^[@A-Z!#$%&]+[ ][-0-9]/ {
#  print "Control with result " FILENAME
    subdir = "control"
    namepos = 3
    
    name = $namepos
    augdir = DST subdir
    res = DST name
    files[name] = 1
    
    sep = ""
    for (i = namepos; i <= NF; i++)
    {
        printf("%s%s", sep, $i) >> res
        sep = " "
    }
    print "" >> res
}

/^[@A-Z!#$%&]+[ ][a-z]/ {
#  print "Control with expression " FILENAME
    subdir = "control_expr"
    namepos = 2

    name = $namepos
    augdir = DST subdir
    res = DST name
    files[name] = 1
    
    sep = ""
    for (i = namepos; i <= NF; i++)
    {
        printf("%s%s", sep, $i) >> res
        sep = " "
    }
    print "" >> res
}

/^[-0-9].*/ {
#  print "Result " FILENAME
    subdir = "simple"
    namepos = 2

    name = $namepos
    augdir = DST subdir
    res = DST name
    files[name] = 1
    
    sep = ""
    for (i = namepos; i <= NF; i++)
    {
        printf("%s%s", sep, $i) >> res
        sep = " "
    }
    print "" >> res
}

/^[a-z].*/ {
#  print "Expression " FILENAME
    subdir = "simple_expr"
    namepos = 1

    name = $namepos
    augdir = DST subdir
    res = DST name
    files[name] = 1
    
    sep = ""
    for (i = namepos; i <= NF; i++)
    {
        printf("%s%s", sep, $i) >> res
        sep = " "
    }
    print "" >> res
}

END {
    mkfilename = DST "files.mk"
    printf ("%s :=", mkvar_varname) > mkfilename
    for (name in files)
    {
        system("sort -u -o " DST name " " DST name)

        printf (" \\\n  %s", name) > mkfilename
        
        close(DST name)
    }
    
    close(mkfilename)

    
    print "Done"
}
