BEGIN{
    numOfRows = 0;
    numOfWords = 0;
}

{
    numOfRows++;
    numOfWords+=NF;

}

{
    for(i = 1; i <= NF; i++){
        while(length($i) < 5){
            $i = $i"0";
        }
    }
    print
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;
}