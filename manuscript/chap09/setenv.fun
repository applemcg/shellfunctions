setenv () 
{ 
    : ~ NAME value ...;
    : exports NAME to the environment,;
    : set to value ...;
    : date: 2017-08-23;
    : date: 2018-02-16;
    [[ $# -lt 1 ]] && return;
    local na=$1;
    shift;
    eval $na=\"$*\";
    export $na
}
