str="/home/rustam/Desktop/manualDir/name.txt"
echo ${str##*.}
echo ${str##*/}
echo ${str/home/rustam}
echo ${str%.txt}
echo ${str%.txt}.old
