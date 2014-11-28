#include <stdio.h>

int f(int n)    //Se n è uguale a 1 o è divisibile ritorna 0 -> se n è primo torna 1
{
    int i;
    if (n==1) return 0;
    for (i=2;i<n;i++)
        if ((n%i) == 0)
            return 0;
    return 1;
}

int g(int a, int b) //controlla quante volte b^r (con r >=2) è divisore di a e ritorna r
{
    int r=1; int e;
    for (e=0;(a%r)==0;r*=b, e++)
        ;
    return e-1;
}

int h(int a)        //Data la scomposizione in fattori primi di a, cerca l'esponente maggiore tra i fattori (che partono da 2)
{
    int e=0; int i;
    for (i=2;i<=a;i++)
        if (g(a,i)>e) e=g(a,i);
    return e;
}

main()
{
    printf ("%i\n",h(3));
    printf ("%i\n",h(10));
    printf ("%i\n",h(20));
    printf ("%i\n",h(256*11));
    printf ("%i\n",h(27));
}
