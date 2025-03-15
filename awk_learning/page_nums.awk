BEGIN{
}
{
    array[NR] = $NF
    
    print
}END{
    sum=0
    for(i=0;i<length(array);i++){
        sum+=array[i];
        print [A-C]
    }
    print "sum: " sum
}