BEGIN{
	s = 0	
}{
	s += $2
}END{
	printf "sum is %d\n", s
}