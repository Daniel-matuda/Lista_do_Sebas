/*
5. Considere as seguintes definições e inicializações:

    char c = ‘T’, d = ‘S’;
    char *p1 = &c;
    char *p2 = &d;
    char *p3;
    
O que será mostrado na tela quando o código a seguir for executado em sequência?

p3 = &d;
 printf( ) de *p3?
p3 = p1;
 printf( ) de *p3?
*p1 = *p2;
 printf( ) de *p1?
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>

char c = 'T';
char d = 'S';
char *p1 = &c;
char *p2 = &d;
char *p3;

int main ()
{   
    printf("O ponteiro depois que (p3 = &d), *p3  é:\t ");
    p3 = &d;
    printf("%.1s\n\n", p3);
    
    printf("Agora que (p3 = p1), o ponteiro *p3 é:\t ");
    p3 = p1;
    printf("%.1s\n\n", p3);
    
    printf("O ponteiro depois de (*p1 = *p2) p1 é:\t ");
    *p1 = *p2;
    printf("%.1s", p1);
    
    return 0;
}





