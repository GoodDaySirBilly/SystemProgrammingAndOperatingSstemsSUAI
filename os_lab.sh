#!/bin/bash


tmp1=0
for i in `ls`
do

    
    if [[ tmp1 -lt `stat -c %s $i` ]] then
        
        tmp1=$(stat -c %s $i)

    fi

done

echo "itog:"
echo $tmp1
