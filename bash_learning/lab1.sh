#!/bin/bash

set -e

LOGFILE="output.log"
> "$LOGFILE"
echo "$(date '+%Y-%m-%d %H:%M:%S') - Начало" >> "$LOGFILE"

echo "1. Remove file"
echo "2. Copy file to path"
echo "3. Rename file to new name"

echo "$(date '+%Y-%m-%d %H:%M:%S') - Menu printed" >> "$LOGFILE"

read -p "Enter num what do you want: " com
echo "$(date '+%Y-%m-%d %H:%M:%S') - Com read = ${com}" >> "$LOGFILE"

case "$com" in
    1)
    read -p "Enter filename: " f
    rm $f
    echo "$(date '+%Y-%m-%d %H:%M:%S') - File ${f} removed" >> "$LOGFILE"
    ;;

    2)
    read -p "Enter filename: " f
    read -p "Enter path: " p
    cp $f $p
    echo "$(date '+%Y-%m-%d %H:%M:%S') - File ${f} copied to ${p}" >> "$LOGFILE"
    ;;

    3)
    read -p "Enter filename: " f1
    read -p "Enter new filename: " f2
    mv $f1 $f2
    echo "$(date '+%Y-%m-%d %H:%M:%S') - Name of file ${f1} changed to ${f2}" >> "$LOGFILE"
    ;;

    *)
    echo "Try again and enter existing command"
    echo "Bad command" >> "$LOGFILE"
    ;;

esac

echo "$(date '+%Y-%m-%d %H:%M:%S') - Конец" >> "$LOGFILE"
echo "Логи сохранены в $LOGFILE"

