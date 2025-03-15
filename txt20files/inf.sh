#!/bin/bash

trap 'echo "Terminated by user"; exit 0' SIGINT 

x=1
while [ $x -le $x ]
do	
 	x=$(( $x + 1 ))
done
