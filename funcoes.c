

#include <stdio.h>
#include <string.h>
#include "defines.h"



// return result 'no' and 'yes'
// return 0x00 error
char * ConcatRemove (char *s, char *t, unsigned char k){

    unsigned char i,operations=0;
    unsigned char size_s, size_tt;
    char string[TAMANHO_PADRAO_STRING];
    unsigned char equal_string;

    memset(string,0x00,TAMANHO_PADRAO_STRING);

    size_s=strlen(s);
    size_tt=strlen(t);

    if(size_s>TAMANHO_PADRAO_STRING){
        error=ERROR_STRING_GRANDE;
        return 0x00;
    }
    if(size_tt>TAMANHO_PADRAO_STRING){
        error=ERROR_STRING_GRANDE;
        return 0x00;
    }

    #ifdef DEBUG
        printf("\nsize s: %d ",size_s);
        printf("\nsize t: %d ",size_tt);
    #endif

    equal_string=TRUE;
    for(i=0;i<size_tt;i++){
        if(s[i]!=t[i]){
            operations=size_s-i;
            equal_string=FALSE;
            break;
        }else{
            string[strlen(string)]=s[i];
        }
    }
    if(equal_string==TRUE){
        operations=size_s-i;
    }

    for(i=strlen(string);i<size_tt;i++){

        string[i]=t[i];
        operations++;

    }

    #ifdef DEBUG
        printf("%s - operations: %d",string,operations);
    #endif

    if(operations>k){
        printf("\nno");
        return "no";
    }

    printf("\nyes");
    return "yes";



}


/*
Função vai retornar a string passada apenas com os caracteres existentes entre a até z
exemplo: passando: "Bla BLA abc23 t"  vai retornar "laabct"

return 0  erro
return 1 sucesso
*/
unsigned char filter_string_a_z(char *string){
    char stringNew[TAMANHO_PADRAO_STRING];
    unsigned char i;
    unsigned char size_string;

    memset(stringNew,0x00,TAMANHO_PADRAO_STRING);
    size_string=strlen(string);

    if(size_string>TAMANHO_PADRAO_STRING){
        error=ERROR_STRING_GRANDE;
        return 0x00;
    }
    for(i=0;i<size_string;i++){

        //0x61 = 'a'  0x71 ='z'
        if((string[i]>=0x61) && (string[i]<=0x7A) ){

            stringNew[strlen(stringNew)]=string[i];

        }
    }

    memset(string,0x00,TAMANHO_PADRAO_STRING);
    strcpy(string,stringNew);

    #ifdef DEBUG
    printf("\nString: %s\n",stringNew);
    #endif

}
