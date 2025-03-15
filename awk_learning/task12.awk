BEGIN{
    numOfRows = 0;
    numOfWords = 0;
}

{
    numOfRows++;
    numOfWords+=NF;

}

{
    tmp = $numOfRows;
    $numOfRows = "";
    print tmp, $0
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;
}