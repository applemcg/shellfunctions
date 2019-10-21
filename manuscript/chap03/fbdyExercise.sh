
    declare -f hello             # as before
    echo === 1 ===
    fbdy () { declare -f $1; }   # the simple version
    fbdy hello                   # same as before
    echo === 2 ===    
    fbdy fbdy                    # no kidding!, so why not ...
    echo === 3 ===    
    fbdy () { declare -f ${1:-fbdy}; }   # so ...
    fbdy                         # shows how to do it!, and
    echo === 4 ===        
    fbdy () { declare -f ${*:-fbdy}; }      # permits ...
    fbdy hello fbdy              # whew, let's take a break

