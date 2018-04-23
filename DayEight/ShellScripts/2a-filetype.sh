#!/bin/bash

if [ $# -lt 1 ]
then
	echo 'Usage: ./2a-filetype.sh filename/directoryname'
	exit 1
fi
if [ -d $1 ]
then
	echo 'DIRECTORY!'
elif [ -e $1 ]
then
	echo 'FILE!'
elif [ ! -e $1 ]
then
	echo $1 'DOES NOT EXIST!'
else
	echo 'SOMETHING ELSE!'
fi
exit 0

