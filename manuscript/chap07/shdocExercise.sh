    _shdoc () 
    { 
        : date: 2018-02-16;
        report_notfunction $1 && return 1;
        echo "function ${1}_doc {";
        declare -f $1 | shd_justcolon;
        echo "}"
    }
    shdoc () 
    { 
        : this is a shell doclib "shdoc" comment;
        : an shdoc comment is the first ":"-origin lines;
        : in the shell function, the rest being the executable.;
        : 2019-01-28 use local _shdoc and produce declare -f format;
        foreach _shdoc ${*:-$(myname)}
    }
    shd_justcolon () 
    { 
        : returns leading colon-comments from a SINGLE function;
        report_notpipe && return 1;
        awk '
        NR > 2 {
                 if ( $1 !~ /^:/ ) exit
                 else              print
               }
        '
    }
    myname () 
    { 
        : ~ [n];
        : returns name of caller OR callers caller ...;
        : date: 2018-02-16;
        echo ${FUNCNAME[${1:-1}]}
    }
