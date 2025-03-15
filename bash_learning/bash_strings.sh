#!/bin/bash

set -e

read -p "Enter string: " string

echo "1. Length of string"
echo "2. Take substr(enter pos and len)"
echo "3. Take str - min substr(enter substr)"
echo "4. Take str - max substr(enter substr)"
echo "5. Replace 1 substring by replacemant(enter both)"
echo "6. Replace all substring by replacemant(enter both)"

read -p "Enter number of command: " com

if [[ com -gt 6 || com -lt 1 ]]; then
    com=7
fi

case "$com" in
    1)
    echo "Length: ${#string}"
    ;;
    2)
    read -p "Please enter start index(0 for begin): " pos
    read -p "Please enter num of output symbols: " len
    echo "Substr: ${string:pos:len}" 
    ;;
    3)
    read -p "Please enter substr: " subs
    echo "Str minus sbstr: ${string#subs}"
    ;;
    4)
    
    ;;
    5)
    
    ;;
    6)
    
    ;;
    7)
    echo "Try again and enter existing command"
    ;;
esac