//The trip
//http://www.programming-challenges.com/pg.php?page=downloadproblem&format=html&probid=110103
#include <cstdio>

#define MAX 1000
#define SCALE 100

int main() {
    double tmp;
    int a[MAX];
    int  m, r, i, j, s, n;
    while(scanf("%d", &n) != EOF && n != 0){
        s = 0;
        for(i = 0; i < n; i++){
            scanf ("%lf", &tmp);
            a[i] = tmp * SCALE + 0.5;
            s += a[i];
        }
        m = s / n;
        r = s % n;
        j = 0;
        s = 0;
        for(i = 0; i < n; i++){
            if(a[i] > m){
                s += (a[i] - m);
                j++;
            }
        }
        printf ("$%.2f\n", (double)(s-(r>j?j:r))/ SCALE);       
    }
    return 0;
}