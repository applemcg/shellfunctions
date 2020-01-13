
chk_status () {    
    [[ -n $(df -kt |grep 9[4-9]%) ]]  && {
        warn_status "$1" ${*:-2}
        exit 1
    }
    ok_status "$1"
}
