
     set a b c       #  set positional parameters to "a b c"
     echo $*         #  show them
     echo $#         #  how many?
     echo here is One: $1
     eval echo here is the Last: \$$#
     echo here is Two: $2
     echo here is Two: ${2:-two}
     echo here is Four: ${4:-four}
     alias ea="echo $# $*"
     ea
