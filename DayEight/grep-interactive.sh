#!/bin/bash

echo "Enter pattern to be searched: "
read pattern
echo "Enter filename: "
read filename
grep "$pattern" $filename
echo "The no of lines containing the pattern $pattern are: "
grep -c "$pattern" $filename
