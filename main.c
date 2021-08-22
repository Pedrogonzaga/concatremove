#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "funcoes.h"


int main ()
{
    char s[100], t[100];	// two character arrays
    unsigned char i, j;
    int k;

    memset(s,0x00,100);
    memset(t,0x00,100);
    printf ("Digite a primeira string:\n");
    fgets (s, 100, stdin);	// Read string1 from stdin, of maximum length 100

    filter_string_a_z((char*)&s);


    printf ("Digite a segunda string:\n");
    fgets (t, 100, stdin);	// Read string2 from stdin, of maximum length 100

    filter_string_a_z((char*)&t);




    do{
    printf ("Digite um número de operações <=100:\n");
    scanf ("%d", &k);

    }while(k>100 && k>0);


    ConcatRemove(s,t,k);



    return 0;
}
