///The 3n + 1 Problem
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110101&format=html
#include <iostream>

int GetCycleLength(int);
int GetMaxCycleLength(int, int);

int main(){
    int i,j;
    while(std::cin >> i >> j) {
        std::cout << i << " " << j << " " << GetMaxCycleLength(i, j) << std::endl;
    }
    return 0;
}

int GetMaxCycleLength(int i, int j){
    int m = 1;
    if(i > j) std::swap(i, j);
    for(; i <= j; i++) {
        int m0 = GetCycleLength(i);
        if( m0 > m ) {
            m = m0;
        }
    }
    return m;
}

int GetCycleLength(int x) {
    int i = 1;
    while(x != 1){
        if(x & 1 == 1){
            x = (3*x + 1) >> 1;
            i+=2;
        } else {
            x >>= 1;
            i++;
        }
    }
    return i;
}