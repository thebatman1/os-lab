#!/bin/bash

echo 'Enter a word: '
read word
echo 'Enter a filename: '
read filename
if [ ! -e $filename ]
then
	echo 'File not Found!!'
	exit 1
fi
grep -o $word $filename | wc -l
exit 0
