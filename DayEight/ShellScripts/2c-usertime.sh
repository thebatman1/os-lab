#!/bin/bash

echo "Enter a user name"
read name
uinfo=`who | grep -w $name`
if [ $? -ne 0 ]
then
	echo "User not available!"
else
	echo "User is there!"
	tm=`who | grep -w $name | tr -s " " | cut -d " " -f4`
	min=`echo $tm | cut -d ":" -f2`
	hrs=`echo $tm | cut -d ":" -f1`
	cmin=`date "+%M"`
	chrs=`date "+%H"`
	if [ $chrs -lt $hrs ]
	then
		hrs=`expr 24 - $hrs + $chrs`
	else
		hrs=`expr $chrs - $hrs`
	fi
	if [ $cmin -lt $min ]
	then
		min=`expr 60 - $min + $cmin`
	else
		min=`expr $cmin - $min`
	fi
	echo "Login period(hrs:min): $hrs:$min"
	exit 0
fi
