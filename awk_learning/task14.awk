BEGIN{
    numOfRows = 0;
    numOfWords = 0;
    numOfFiles = 0; 
    numOfSymbols = 0;

    numOfRowsInFile = 0;
    print "Redacted table:"
}

{
    if(FNR == 1){
        numOfRowsInFile = 0;
        numOfFiles++;
        print "\nSurname    Name    Fathername    Phone    Points\n"
    }
    numOfRowsInFile++;
    numOfRows++;
    numOfWords+=NF;
    numOfSymbols+=length($0);

    if(length > 25){
        tmp = $NF;
        $NF = $numOfRowsInFile;
        $numOfRowsInFile = tmp;
    }
    
    print $0
}

END{
    printf "\nNum Of files: %s\nNum of rows: %d\nNum of words: %d\nNum of symbols: %d\n", 
    numOfFiles, numOfRows, numOfWords, numOfSymbols;
}
