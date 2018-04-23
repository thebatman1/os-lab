#!/bin/bash

if [ $# -lt 2 ]
then
	echo 'Usage: ./7-checksimilarity.sh file1 file2'
	exit 1
fi
if [ ! -e $1 -o ! -e $2 ]
then
	echo 'One of the files is missing. Please check arg list'
	exit 2
fi
cmp --silent $1 $2  && rm $2 || echo 'Files are different'
exit 0
