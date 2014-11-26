#include <stdio.h>

char* f(char* s, char c)    //trova l'indice di c all'interno di una stringa (o arriva alla fine della stringa)
{
    for (; *s!=c && *s!='\0'; s++) ;
    
    if (*s!='\0') s++;
    
    return s;
}

void p(char* s, char c)     //stampa tutti i caratteri fino al carattere c o fino alla fine della stringa
{
    for (; *s!=c && *s!='\0'; s++)
        printf ("%c",*s);
}

void g(char* s, char c)     //'spezza' la stringa sul carattere e inverte i pezzi
{
    if (*s=='\0') return;
    
    g(f(s,c),c);
    
    /*
     vengono generati un certo numero di funzioni g, ognuna con s che punta allo spazio o a 0. Quando arriva a 0
     le chiamate ricorsive terminano, e quindi con la prossima istruzione viene stampata la stringa dal carattere c alla
     fine e in seguito dal pezzo ancora minore a c ecc...
     */
    
    p(s,c);
}

int main()
{
    g("sei uno zero",' ');
    printf ("\n");
}
