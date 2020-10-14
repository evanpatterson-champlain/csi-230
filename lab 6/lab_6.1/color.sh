#!/bin/bash

# color.sh
# case statements
# evan patterson
# lab 6.1
# date 10/13/2020

red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[1;35m'
purple='\033[0;35m'
default='\033[0m'

read -p "What is your favorite color (red, green, blue, yellow or magneta)? " color
color=${color^^}

if [[ -z ${color} ]]; then
  echo "You didn't pick a color"
  exit 0
fi

echo "${color} selected"
case ${color} in
  "RED") selected_color=$red
  ;;
  "BLUE") selected_color=$blue
  ;; 
  "PURPLE") selected_color=$purple
  ;;
  "MAGENTA") selected_color=$magenta
  ;;
  "YELLOW") selected_color=$yellow
  ;;
  *) selected_color=$default
  ;;
esac


echo -e "${selected_color}Your selected color is ${color}${default}"


