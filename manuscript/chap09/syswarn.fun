
syswarn () { 
    echo "\n$(date) hostname=$1 NEEDS ATTENTION:" 
    echo "\n\r\rWARNING these file systems are approaching being full on hostname=$1:\r"
    echo "\r" 
    echo "Filesystem 1024-blocks Used Free %Used Mounted on\r"
    echo "${x}\r" 
    echo "\r"
    echo ">>>>>>>>>> THIS CAN POTENTIALLY CAUSE LOSS OF DATA <<<<<<<<<\r\r" 
    find /tmp -xdev -size +2048 -ls |sort -r +6
}
