#include <stdio.h>

int r(int n)    //somma tutte le cifre e moltiplica per 10, eccetto la più rilevante, che viene aggiunta alla fine
{
    if (n<10)
        return n;
    return 10*(n%10)+r(n/10);
}

int main()
{
    int i;
    for (i=0;i<101;i++)
        if (i==r(i)) printf("%i\n",i);          //stampa solo i numeri che una volta invertite le cifre sono uguali al numero di partenza
}
