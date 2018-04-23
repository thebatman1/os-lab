#!/bin/bash

echo 'Enter a number greater than 0'
read num
if [ $(($num % 2)) = 0 ]
then
	echo 'Even'
else
	echo 'Odd'
fi
