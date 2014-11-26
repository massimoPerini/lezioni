#include <stdio.h>
#include <string.h>

int b(int n, int i)//divide n per 2^n e ritorna 1 se il risultato è dispari, 0 altrimenti
{
    if (i==0) return n%2;
    return b(n/2, i-1);
}
int u(int n, int i) //n^i
{
    if (i==0) return 1;
    return n*u(n,i-1);
}
void p(char* s, int c)
{
    int i;
    for (i=0;s[i]!='\0';i++)//per ogni carattere
        if (b(c,i)) printf ("%c",s[i]);     //divide c per 2^(i), con 0<i <lunghezza parola. Se il numero è dispari, scrive la lettera con indice i
    printf ("\n");
}

//int f(char* s)
void f(char* s){
    int i,l=u(2,strlen(s));//l=2^lunghezza di s. Nell'es., 16
    for (i=0;i<l;i++)
        p(s,i);//Controlla quando i (da 0 a 15) è divisibile per 2^i (valori 1, 2, 4, 8).
                /*Se il risultato non è pari, stampa la corrispondente lettera 
                Es 0/1->0->pari->non scrivo ecc. nell'es: (1->i=0), (1->i=1), (3->i=0, 1->i=1), 
                (1->1=2), (5->i=0), (1->i=2), ecc.*/
}

int main(int argc, char** argv)
{
    f("ciao");
}
