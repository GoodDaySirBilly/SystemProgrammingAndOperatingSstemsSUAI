BEGIN{
    numOfRows = 0;
    numOfWords = 0;
}

{
    numOfRows++;
    numOfWords+=NF;

}

{
    l = length($numOfRows)/2;
    $numOfRows = substr($numOfRows,1,l)"MDL"substr($numOfRows,l+1);
    print
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;
}