#!/bin/bash

if [ $# -lt 1 ]
then
	echo 'Usage: ./4b-deletelines.sh filename [filenames...]'
	exit 1
fi
echo 'Enter the word'
read word
for file in $*;
do
	sed "/$word/d" $file | tee temp
	mv temp $file
done
