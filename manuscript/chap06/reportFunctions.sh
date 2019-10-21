    report_notfunction () 
    { 
        : returns: TRUE when 1st arg "ISN'T" a function,;
        : ... FALSE if it IS a function;
        : date: 2018-02-16;
        declare -f $1 > /dev/null && return 1;
        report_usage $1 "ISN'T" a function
    }
    report_notpipe () 
    { 
        : returns: TRUE when STDIN "ISN'T" a pipe;
        : ... FALSE if stdin is a pipe;
        : date: 2018-02-16;
        [[ -p /dev/stdin ]] && return 1;
        report_usage "ISN'T" reading a pipe
    }
    report_usage () 
    { 
        : writes: usage message of report_... caller FAILURE to STDERR;
        : date: 2018-03-30;
        echo USAGE $(myname 3): $* 1>&2
    }
