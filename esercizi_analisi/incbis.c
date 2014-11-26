#include <stdio.h>
#include <string.h>

void i(char* s, char b, int c)  //sostituisce a s il valore di b per tutti i caratteri fino a quando non trova un carattere la cui differenza con b è > di c-1 (o la stringa finisce)
{
    if (*s=='\0') return;
    if ((*s-b)<c-1) (*s)++;
    else
    {
        *s=b; i(s+1,b,c);
    }
}

int main(int argc, char** argv)
{
    char *s=strdup("xxx"), c=*s;
    int j;
    for (j=0;j<12;j++,i(s,c,3))
        printf ("%s\n",s);      //xxx - yxx - zxx -  -xyx
}
