warn_status () {
    local hostname=$1; shift; : following args replace default subscriber list, good to test
    local subscribers=${*:-“thom email@removed email@removed”}
    local subject=”!!!!! CHECK %USED FOR FILE SYSTEMS ON hostname = $hostname !!!!!”
    syswarn “$hostname” | tee $warning | mail -s “subject” $subscribers
    echo “END WITH email $(date) on hostname=$hostname” 
}
