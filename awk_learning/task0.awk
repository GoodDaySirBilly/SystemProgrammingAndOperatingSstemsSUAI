BEGIN{
    numOfRows = 0;
    numOfWords = 0;
}

{
    numOfRows++;
    numOfWords+=NF;

}

/s/{
    if($2 == "-"){
        hsPs = 0;
    }else{
        hsPs = 1;
    }

    printf "User: %s; Has password: %s; HomeDir: %s\n", $1, hsPs, $3
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;
}