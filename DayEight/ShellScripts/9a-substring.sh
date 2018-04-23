#!/bin/bash

echo 'Enter a string: '
read s
echo 'Enter a substring: '
read sub
if echo "$s" | grep -q "$sub" 
then
	echo "$sub is a substring of $s"
else
	echo "Substring not found!"
fi
