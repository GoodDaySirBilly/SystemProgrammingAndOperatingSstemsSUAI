BEGIN{
    numOfRows = 0;
    numOfWords = 0;
    numOfSymbols = 0;

    numOfRowsInFile = 0;
}

{
    if(FNR == 1){
        numOfRowsInFile = 0;
    }
    numOfRows++;
    numOfRowsInFile++;
    numOfWords+=NF;
    numOfSymbols+=length($0);
    
}

{
    if((numOfRowsInFile) % 2 !=0){
        smstr = ""
        for(i = NF; i > 0; i--){
            if(i == NF){
                smstr = $i
            }else{
                smstr = smstr" "$i
            }
        }
        print smstr
    }else{
        print $0
    }
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\nNum of symbols: %d\n", 
    FILENAME, numOfRows, numOfWords, numOfSymbols;
}