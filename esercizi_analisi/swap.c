#include <stdio.h>

void swap(int *a, int *b)   //Inverte i puntatori
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int b=1,c=2;
    printf ("b=%i, c=%i\n",b,c);
    swap(&b,&c);
    printf ("b=%i, c=%i\n",b,c);
}
