#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int s1, int s2)             //Ritorna il numero maggiore (o uguale)
{
    if (s1>s2) return s1;
    return s2;
}
char* s(char* s1, char* s2)
{
    char* r=(char*)malloc(sizeof(char)*max(strlen(s1),strlen(s2))+1);       //Allocazione dinamica di un array. R ha lunghezza pari al maggiore tra s1 e s2
    int c=0;
    int i;
    for (i=0;s1[i]!='\0';i++)       //Scorro tutta s1
    {
        r[i]=((s1[i]-'a')+(s2[i]-'a')+c)%2+'a';
        /*La lettera a in codifica ASCII corrisponde al valore 97. Pertanto, togliendo
        a trova lo 'scostamento' dall'inizio dell'alfabeto (A != a, A= 65 in ASCII)
        ((somma gli scostamenti+media precedente)0=pari, 1=dispari)trasforma in lettera-> le lettere potranno essere solo a o b */
        c=((s1[i]-'a')+(s2[i]-'a')+c)/2;//(Somma degli scostamenti + media precedente)/2
    }
    r[i++]=c+'a';//Alla fine aggiunge la media
    r[i]='\0';//Indica che la parola è finita
    return r;
}
int main()
{
    printf ("%s\n",s("aaba","aabb"));//[97, 97, 97, 97, 98, 0]->"a, a, a, a, b"
    printf ("%s\n",s("abab","baba"));//[98, 98, 98, 98, 97, 0]
    printf ("%s\n",s("aaaa","bbbb"));//[98, 98, 98, 98, 97, 0]
}
