#!/bin/bash

if [ $# -lt 3 ]
then
	echo 'Usage: ./4a-showlines.sh filename start end'
	exit 1
fi
if [ ! -e $1 ]
then
	echo 'File not found!'
	exit 4
fi
if [ $2 -lt 1 -o $2 -ge $3 -o `cat $1 | wc -l` -lt $3 ]
then
	echo 'Invalid range!'
	exit 2
fi
start=$2
end=$3
for ((i = $start; i <= $end; i++));
do
	echo `sed -n ${i}p $1`
done
exit 0
