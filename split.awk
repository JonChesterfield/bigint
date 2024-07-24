#!/usr/bin/gawk -f

# Takes a directory then N files
# Does a top level division into control/ and simple/ based on
# whether the test case sets a control block, then writes the cases to
# files named for the operation. Any cases that are missing the result
# value go under expr_$op to distinguish from complete cases


BEGIN {
  DST=ARGV[1]
  ARGV[1] = ""
  print "Writing with base " DST

  mkvar_prefix = DST
}

function out(param_subdir, param_name, param_contents)
{
    augdir = DST param_subdir
    if (! (augdir in dirs))
    {
        sys = "mkdir -p " augdir
        # print(sys)
        system(sys)
        dirs[augdir] = 1
    }


    res = augdir "/" param_name
    files[param_subdir,param_name] = 1
    print param_contents >> res
}


/^[@A-Z!#$%&]+[ ][-0-9]/ {
#  print "Control with result " FILENAME
    out("control", $3, $0)
}

/^[@A-Z!#$%&]+[ ][a-z]/ {
#  print "Control with expression " FILENAME
    out("control_expr", $2, $0)
}

/^[-0-9].*/ {
#  print "Result " FILENAME
    out("simple", $2, $0)
}

/^[a-z].*/ {
#  print "Expression " FILENAME
    out("simple_expr", $1, $0)
}

END {
    for (combined in files) {        
        split(combined, separate, SUBSEP)
        subdir = separate[1]
        name = separate[2]

        mkfilename = subdir "/" subdir".mk"
        
        if (! (mkfilename in mkfiles))
        {
            # print "Unknown " mkfilename
            system("rm -f "DST mkfilename)
            printf ("%s%s :=",  mkvar_prefix, subdir) >> DST mkfilename
            mkfiles[mkfilename] = 1
        }

        printf (" \\\n  %s", name) >> DST mkfilename

        
        f = DST subdir "/" name
        # print("Sorting " f)
        close(f)
        # system("sort -u -o " f " " f)
    }

    combinedmkfile = DST "files.mk"
    system("rm -f " combinedmkfile)
    print "$(if $(FUZZ_FILES_DIR),,$(error require definition for fuzz_files_dir))" >> combinedmkfile
    for (f in mkfiles)
    {
        printf ("include $(FUZZ_FILES_DIR)%s\n", f) >> combinedmkfile
        close(DST f)
    }
    close(combinedmkfile)

    
    print "Done"
}
