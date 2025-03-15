#!/bin/bash

read -p "Enter a: " a
read -p "Enter b: " b
read -p "Enter c: " c

if [[ "$a" -lt "$b" ]]
then 
    if [[ "$b" -lt "$c" ]]
    then
        echo "a <= b <= c"
    else
        if [[ "$a" -gt "$c" ]]
        then
            echo "c <= a <= b"
        else
            echo "a <= c <= b"
        fi
    fi
else
    if [[ "$b" -gt "$c" ]]
    then
        echo "c <= b <= a"
    else
        if [[ "$a" -gt "$c" ]]
        then
            echo "b <= c <= a"
        else
            echo "b <= a <= c"
        fi
    fi
fi