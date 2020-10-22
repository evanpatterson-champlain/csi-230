#!/bin/bash

# file: mail.sh
# brief:  create emails for new and existing users
# author: evan.patterson
# project: project 2, user provisioning
# date: 10/22/2020


# make sure is root before doing anything
if [[ $(/usr/bin/id -u) -ne 0 ]]; then
  echo "Must run as root"
  exit 1
fi


# check for -f because
# -f <filename> is really the
# only way to use this script
if [[ $1 != "-f" ]]; then
  echo "$0 usage: [-f input file]"
  exit 1
else
  if [[ -z $2 ]]; then
    echo "No input."
    exit 1
  fi
fi

# get arguments
while getopts "f:" arg; do
  case $arg in
    f) filename=$OPTARG;
  esac
done

# make sure file exists
if [ -f $filename ]; then
  echo "File exists, creating passwords."
else
  echo "File does not exist."
  exit 0
fi




# define subject for the email here
sbjct="Linux Lab: Password Reset"

endl=$'\n'


# main loop
while read -r line;
do

  randPass=$(openssl rand -base64 12)
  usernm=$(echo "$line" | cut -d "@" -f 1)
  msgName="Dear ${usernm}, you have been generated a new password."
  msgPass="This is your new password: ${randPass}"
  echo "${msgName} ${endl}${msgPass}" | mail -s "${sbjct}" ${line}
  pass=$(perl -e 'print crypt($ARGV[0], "password")' $randPass)

  if [ $(getent passwd "$usernm") ]; then
    echo ${usernm}:$randPass | chpasswd
    echo "Changing password for ${usernm}"
  else
    useradd -m -p "$pass" ${usernm}
    echo "Creating new account for ${usernm}"
  fi

  authoutpt=$(passwd -e ${usernm})

done < "$filename"


echo "${endl}Done reading emails from file.${endl}"

exit 0
