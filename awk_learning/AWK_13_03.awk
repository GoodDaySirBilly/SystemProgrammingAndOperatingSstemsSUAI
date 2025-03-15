BEGIN{
    numOfRows = 0;
    numOfWords = 0;

    numOfFiles = 0;
    numOfDirectories = 0;
    sumSizeFiles = 0;
    printf "NAME        TYPE       SIZE      DATE"
}

{
    numOfRows++;
    numOfWords+=NF;
}

{
    name = $9;
    type = "a";
    size = $5;
    date = $6" "$7" "$8;
    tmp = substr($1,1,1);
    if(tmp == "-"){
        type = "file";
        numOfFiles++;
        sumSizeFiles+=size;
    }else if(tmp != "t"){
        type = "directory";
        numOfDirectories++;
    }

    n = split(name,arr,".")
    printf "%-15s  %-5s  %-5s  %-20s\n",name,type,size,date  
    
}

END{
    printf "\nFile: %s\nNum of rows: %d\nNum of words: %d\n", 
    FILENAME, numOfRows, numOfWords;

    printf "\nNum of Files: %s\nNum of directoris: %s\nSummary size: %d\n",
    numOfFiles,numOfDirectories,sumSizeFiles;
}