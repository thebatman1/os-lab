#!/bin/bash

if [ $# -eq 0 ]
then
	echo 'Usage: ./11-chown.sh file newuser [newgroup]'
	exit 1
elif [ $# -eq 2 ]
then
	if [ $( id -u $2 ) = 1 ]
	then
		echo 'User does not exist!'
	else
		echo 'Ownership changed!'
		chown $2 $1
	fi
elif [ $# -eq 3 ]
then
	if grep -q $3 /etc/group
	then
		echo 'Ownership changed!'
		chown $2:$3 $1
	else
		echo "Group doesn't exist"
	fi
fi
