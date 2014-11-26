#include <stdio.h>
int f(char a[], char b[])           //1 se la seconda parola contiene le lettere ordinate della prima, 0 altrimenti
{
    int i=0,j=0;
    while (a[i] != '\0' && b[j] != '\0')
    {
        if (a[i]==b[j])
            i++;
        j++;
    }
    if (a[i]=='\0') return 1;
    return 0;
}
int main()
{
    printf ("%i\n",f("ciao","acciacco"));//1
    printf ("%i\n",f("ciao","scaccio"));//0
    printf ("%i\n",f("osso","ostracismo"));//1
    printf ("%i\n",f("consistenza","insistenza"));//0
}
