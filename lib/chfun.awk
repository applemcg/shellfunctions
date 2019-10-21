BEGIN       { fmt = "%s"; prev = "" }           
            { # print NF, $3, $0
	    }
$3 ~ /add/  { 

    printf "ch%dfun () {", $1; 
    printf fmt, prev
    fmt =  " ch%dfun;"
    printf " myfbdy"
    for( i = 4; i<=NF; i++) { printf " %s", $i }
    printf "; }\n"
    prev = $1
}
# delete is an exercise left for the student.
