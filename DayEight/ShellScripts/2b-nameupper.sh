#!/bin/bash

if [ $# -lt 1 ]
then
	echo 'Usage: ./2b-nameupper.sh filename [filenames....]'
	exit 1
fi
for i in $*; 
do
	if [ -e $i ]
	then
		mv "$i" "${i^^}"
	else
		echo "$i not in current directory!"
	fi
done
exit 0
