#!/bin/bash

# file hostlookup.sh
# iteration
# author evan patterson
# lab 6.2
# date 10/13/2020

filename="$1"

if [ -f $filename ]; then
  echo "Hosts:"
else
  echo "File does not exist"
  exit 0
fi

while read -r line;
do 
  out=$(host -W1 -t A $line)
  if [ $? -eq 0 ]; then
    ip=$(echo $out | cut -d " " -f 4)
    echo ${line},$ip
  else
    echo "${line},not found"
  fi
done < "$filename"
