warn_status () {
    local mailsub=”!!!!! CHECK %USED FOR FILE SYSTEMS ON hostname = $1 !!!!!”
    syswarn “$1” | tee $warning | mail -s “$mailsub” “thom email@removed email@removed”
    echo “END WITH email $(date) on hostname=$1” 
}
