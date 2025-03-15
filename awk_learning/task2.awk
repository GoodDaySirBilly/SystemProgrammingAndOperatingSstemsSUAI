BEGIN{
    numOfRows = 0;
    numOfWords = 0;
}

{
    numOfRows++;
    numOfWords+=NF;

}

{
    $numOfRows = $numOfRows"DONE";
    print
    
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;
}