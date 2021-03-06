#define LEN 3

#include <stdio.h>

int f(int a,int b)  //b^i divisibile per a -> trova il max. esponente per cui a è divisibile per b^i
{
    int r=0;
    for (;(a%b)==0;a/=b)
        r++;
    return r;
}

int g(int a)    //ritorna l'esponente per cui a è divisibile per b^esponente (scomponi in fattori primi e prendi l'esponente maggiore)
{
    int r=0; int i;
    for (i=2;i<a;i++)
        if (f(a,i)>r)
            r=f(a,i);
    return r;
}

int h(int a[LEN])       //Ritorna il valore dell'array per cui la scomposizione in fattori primi genera un fattore con l'esponente maggiore tra tutti
{
    int i,m=g(a[0]),n=a[0];
    for (i=1;i<LEN;i++)
        if (g(a[i])>m)
        {
            m=g(a[i]);      //Tengo l'esponente maggiore
            n=a[i];         //n è il valore per cui c'è l'esponente maggiore
        }
    return n;
}

int main()
{
    int a[]={1,2,20};       //2->20 ecc.
    int b[]={125,40,99};
    int c[]={3*3*3*3,11*11*11*11*11,1024};
    printf ("%i, %i, %i\n",h(a),h(b),h(c));
}

