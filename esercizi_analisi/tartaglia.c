#include <stdio.h>
#include <stdlib.h>

int* t(int n,int* a)    //Array di n+1 che inizia e finisce con uno e il resto è la somma della posizione di a e a-1
{
    int i;
    int *r=(int*)malloc(sizeof(int)*(n+1));
    r[0]=1;
    for (i=1;i<n;i++)
        r[i]=a[i-1]+a[i];   //Somma il numero attuale e il precedente
    r[n]=1;
    return r;
}

void s(int n, int* a)   //Stampa il contenuto dell'array
{
    int i;
    for (i=0;i<=n;i++)
        printf ("%d\t",a[i]);
    
    printf ("\n");
}

void tr(int n)  //Scrive il triangolo di tartaglia
{
    int *p=(int*)malloc(sizeof(int));
    int i;
    
    p[0]=1;
    
    s(0,p);
    
    for (i=1;i<=n;i++)
    {
        p=t(i,p);   //[1,1] [1,2,1] [1,3,3,1] [1,4,6,4,1] ecc...
        s(i,p); //Mostra l'array
    }
}

int main(int argc,char** argv)
{
    tr(5);
}
		
		
