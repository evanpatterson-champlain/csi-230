#!/bin/bash

# converter.sh
# iteration
# author evan patterson
# lab 6.2
# date 10/13/2020

usage()
{
  echo "$0 usage: [-f input filed] [-c U(pper) or L(lower)]"
  exit 1
}

while getopts ":f:c:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f ${f} ]]; then
        echo "File exists, here it is:"
      else
        echo "File does not exist"
        exit 0
      fi
    ;;
    c)
      c=${OPTARG}
      if [[ ${c} == "U" || ${c} == "L" ]]; then
        echo "${f} - ${c}"
      else
        usage
      fi
    ;;
    *)
    usage
    ;;
  esac
done
#conversation logic here

while read line
do
  if  [ ${c} == "U" ]; then
    echo $line | tr [:lower:] [:upper:]
  else
    echo $line | tr [:upper:] [:lower:]
  fi
done < $f

exit 0
