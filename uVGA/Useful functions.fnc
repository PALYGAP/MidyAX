// Copy length characters from the string pointed to by << sourcePtr >>
// and from the point pointed to by  << Ptr_sourcePtr >> to the string pointer to by destinationPtr

func copy_nstr(var length, var Ptr_sourcePtr, var destinationPtr)
    var i, tempoChar;

    //destinationPtr := str_Ptr(destination);
    for ( i:=0; i < length ; i++)
        str_GetC(Ptr_sourcePtr,&tempoChar);
        str_PutByte(destinationPtr++, tempoChar);
    next
    str_PutByte(destinationPtr, '\0');
endfunc
