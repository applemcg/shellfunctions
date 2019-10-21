            { # print NF, $3, $0
	    }
$3 ~ /add/  { 

    printf "echo 'ch%ssrc () {'", $1;
    printf "\nfbdy"
    for( i = 4; i<=NF; i++) { printf " %s", $i }
    printf " ;\necho ' }'\n"

}
# delete is an exercise left for the student.
