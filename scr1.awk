BEGIN {
tm = FILENAME
}{
if(FILENAME == tm) {
	print NR, $tm
	NR = 1
}
else {
	
	print ++NR,FILENAME
	
	print ++NR,$tm
	tm = FILENAME
	
}


}END{}

