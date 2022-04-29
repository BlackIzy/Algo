#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int x = 0;
int y = 0;

double fibo(int n) {
    double a = 0;
    if(n==0 || n==1)   {
        a=1;
    }
    else
    {
        a = fibo(n-1) + fibo(n-2);
        x = x+2;
    }


return a;

}


double fiboIter(int n)  {
    int f, fm1, fm2;
    int i;
    fm1 = 1;
    fm2 =1;
    f = 1;
    for(i=2;i<=n;i++)   {
        fm2 = fm1;
        fm1 = f;
        f = fm1 + fm2;
        y++;
    }

    return f;
}


int main() {
    clock_t  start, end, start1, end1;
    float cpu_time_used,cpu_time_used1;
    float tab[8][6];
    tab[0][0] = 1;
    tab[1][0] = 5;
    tab[2][0] = 10;
    tab[3][0] = 20;
    tab[4][0] = 30;
    tab[5][0] = 35;
    tab[6][0] = 40;
    tab[7][0] = 42;
    for(int i = 0; i < 8; i++)
    {
            int j = 1;
            printf("N = %2.f   ;", tab[i][0]);
            start = clock();
            tab[i][j] = fibo(tab[i][0]);
            end = clock();
            cpu_time_used = ( (end - start)) / (float)CLOCKS_PER_SEC;
            start1 = clock();
            float resultat2 = fiboIter(tab[i][0]);
            end1 = clock();
            cpu_time_used1 = ((end1 - start1)) / (float)CLOCKS_PER_SEC;
            printf("Fibo(n) = %2.f et FiboIter(n) = %2.f  ;", resultat2, tab[i][j]);
            j++;
            tab[i][j] = x+1;
            printf("Nombre d'appels recursifs de Fibo %d  ;",x+1);
            j++;
            tab[i][j] = y;
            printf("Nb iterations fiboIter %d  ;", y);
            j++;
            tab[i][j] = cpu_time_used;
            printf(" Temps d'excution de Fibo %f  ;", tab[i][j]);
            j++;
            tab[i][j] = cpu_time_used1;
            printf(" Temps d'excution de FiboIter %f  ;", tab[i][j]);
            j = 0;
            x = 0;
            y = 0;
            printf("\n\n");

    }

return 0;
}


