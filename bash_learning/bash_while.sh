#!/bin/bash

i=0

while [[ i -le 3 ]]
do
    echo $i
    if [[ i -eq 1 ]]
    then
        break
    fi
    let i+=1

    
done
