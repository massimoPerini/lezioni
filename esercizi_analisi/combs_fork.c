#include <stdio.h>
int k(int l)
{
    int i,n=0;
    for (i=0;i<l;i++)
    {
        n*=2;
        if (fork()) n+=1;   //nel c, l'if con 0 è falso, altrimenti è vero.
        //La funzione fork serve per creare altri processi figli. Fork ritorna 0 al figlio e il numero del figlio al padre
        //perciò, il padre per ogni volta che crea un processo (l volte) incrementerà n (e poi lo moltiplica, nell'es. ((1*2+1)*2+1)*2+1), il primo figlio incrementerà n l-1 volte ((1*2+1)*2+1). Il secondo figlio invece parte con n=1, quindi avrà il valore 7 (si genera con i=1) ecc... ecc.
        
        /*
         
                                            p1
                            
                            p1                              p2                      prima iterazione
                    
                    p1              p3           p2                      p5         seconda iterazione
                
            p1            p6    p3      p7   p2        p8           p5      p9      terza iterazione
         
         ecc...
      
         quindi alla fine i processi saranno 2^nIterazioni, quindi 2^4=16
         
         */
    }
    return n;
}

int main()
{
    printf ("%i\n",k(4));
}

