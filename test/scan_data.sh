#!/bin/bash

#The aim for this script is to create text file with list of files from data dir
# it writes the list to a file denoted by supplied cmd argument
# it also writes what is contained in files

for x in `find $1 -type f`
do
variable=`cat $x`
echo "$x $variable"

done
