#include <unistd.h>
#include <stdio.h>

int main()
{
    int a[2]={1,2};
    int b[3]={10,11,100};
    int i=0,j=0;
    if (fork()) i++;
    
    //Da adesso p1 ha i=1 e p2 ha i=0
    
    if (fork())
    {
        //Sia p1 che p2 hanno generato ciascuno 1 processo (es. rispettivamente p3 e p4), che non sono entrati in questo if
        j++;
        if (fork())
            //Sempre p1 e p2 hanno generato ciascuno 1 processo (es. p5 e p6) che non sono entrati solo in quest'ultimo if
            j++;
    }
    
    /*
     Alla fine: 
     p1=tutti gli if: i=1, j=2
     p2=saltato solo il primo if: i=0, j=2
     p3: viene da p1 ma non è entrato al secondo if, quindi ha i=1, j=0
     p4: viene da p2 ma non è entrato al secondo if, quindi i=0, j=0
     p5: viene da p1 ma non è entrato al terzo if, quindi i=1, j=1
     p6: viene da p2, non è entrato al terzo if, quindi i=0, j=1
     
     */
    
    
    printf ("%i\n",a[i]*b[j]);
}
