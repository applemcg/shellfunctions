
ok_status () {
    date 
    find /tmp -xdev -size +2048 -ls |sort -r +6 
    echo "END WITHOUT email $(date) on hostname=$1" 
}
