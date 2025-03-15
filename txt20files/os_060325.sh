#!/bin/sh

LOGFILE="output.log"

> "$LOGFILE"
echo "$(date '+%Y-%m-%d %H:%M:%S') - Начало" >> "$LOGFILE"
for file in *.txt; do
    myfilesize=$(wc -c < "$file")

    if [ "$myfilesize" -le 20 ]; then
        echo "Файл: $file (размер: $myfilesize байт)" | tee -a "$LOGFILE"
        cat "$file" | tee -a "$LOGFILE"
        echo "" | tee -a "$LOGFILE"
    fi
done
echo "$(date '+%Y-%m-%d %H:%M:%S') - Конец" >> "$LOGFILE"
echo "Логи сохранены в $LOGFILE"
