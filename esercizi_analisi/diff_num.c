#include <stdio.h>

int g(int a, int b, int c)      //1 se il resto della continua divisione di b per c è a, 0 altrimenti
{
    for (; c>0; c/=b)
        if (a == (c%b)) return 1;
    return 0;
}

int f(int a, int b) //Il numero di diversi valori da scrivere per porre il numero a in base b???
{
    int n=0;
    for (; a>0; a /= b)
        if (!g(a%b, b, a/b))        //Se il primo resto di a/b è univoco
            n++;
    return n;
}

int main()
{
    printf ("%i\n",f(123,10));  //3
    printf ("%i\n",f(1223,10)); //3
    printf ("%i\n",f(1*123+1*(123*123*123),123));   //
    printf ("%i\n",f(2+2*123+2*(123*123)+2*(123*123*123),123));
    return (0);
}
