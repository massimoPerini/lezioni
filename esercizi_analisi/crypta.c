#include <stdio.h>
#include <strings.h>

char* h(char* s)        //Ritorna il puntatore al carattere successivo a quelli uguali e consecutivi puntati dal puntatore
                        //es. aaabbc  se il puntatore puntava ad a, dopo il puntatore punta al primo b
{
    char c;
    for (c=*s;c==*s;s++);   //Scansiona i caratteri
    return s;
}

void p(char* a, char* b)        //Rende il carattere b il maggiore
{
    char t=*a;
    if (*a>*b) {*a=*b; *b=t;} //Se il carattere puntato dal primo parametro è > di quello puntato dal secondo, li inverto
}

void o(char* s)         //Ordina la stringa in modo crescente (dai caratteri piccoli a quelli grandi)
{
    int i,j,l=strlen(s);
    for (i=0;i<l;i++)          //Passa ogni carattere della stringa
        for (j=0;j+1<l;j++)    //Va fino al penultimo carattere
            p(s+j,s+j+1);      //Passa a p il puntatore al carattere attuale e quello al successivo
                            //->il carattere successivo sarà il maggiore
}

char f(char *s)         //Ritorna il carattere che compare più volte
{
    char c,m=0;
    o(s);                   //Ordino in modo crescente
    for (c=*s;*s!='\0';s=h(s))      //scansiona la stringa avanzando alle lettere diverse (saltando quelle uguali a quella analizzata)
    {
        if ((h(s)-s)>m)             //numero di caratteri uguali e consecutivi a quello iniziale
        {m=h(s)-s; c=*s;}           //m è il massimo numero di caratteri uguali consecutivi, c è il carattere
    }
    return c;
}

int main(int argc, char** argv)
{
    char *s=strdup("fortasse requiris");
    o(s);                           //Ordina s in modo crescente
    printf ("%s\n",s);
    printf ("%c\n",f(s));           //Scrive il carattere che compare più spesso
}
