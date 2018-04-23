#!/bin/bash

echo 'Enter a list of numbers: '
read -a arr
echo 'Enter the element to be searched: '
read x
for a in ${arr[@]};
do
	if [ $x = $a ]
	then
		echo 'Found!'
		exit 0
	fi
done
echo 'Not Found!'
exit 1
