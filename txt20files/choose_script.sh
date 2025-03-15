#!/bin/bash

echo "Please choose script and put number of script:"
echo "1. os_060325.sh"
echo "2. inf.sh"
echo "3. once_more.sh"

read input

case $input in
	1)
	echo `./os_060325.sh`
	;;
	2)
	echo `./inf.sh`
	;;
	3)
	echo `./once_more.sh`
	;;
esac
