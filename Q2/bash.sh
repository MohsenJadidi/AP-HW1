#!/bin/sh

filename="dictionary.txt"
while read -r line; do
    echo $line
done < "$filename"
