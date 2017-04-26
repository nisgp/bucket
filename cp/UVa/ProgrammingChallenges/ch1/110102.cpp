//Minesweeper
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110102&format=html
#include <iostream>
#include <climits>

void update(int, int, int, int*);
void shift(int, int, int*);
void print(int, int, int*);

int main(){
    int i = 1;
    int n, m;
    while((std::cin >> n >> m) && n != 0) {
        if(i != 1) std::cout << std::endl;
        std::cin.ignore(256, '\n');
        std::cout << "Field #" << i++ << ":" << std::endl;
        int size = 3*(m+2);
        int a[size];
        std::fill(a, a + size, 0);
        int iP = 1;
        int jP = iP + m;
        int iU = m + 3;
        int jU = iU + m;
        update(iU, jU, m, a);
        shift(iU - 1, size, a);
        for(int k = n-1; k > 0; k--){
            update(iU, jU, m, a);
            print(iP, jP, a);
            shift(iU - 1, size, a);
        }
        print(iP, jP, a);
    }
    return 0;
}

void update(int i, int j, int m, int* a) {
    char c;
    for(int k = 0; i < j; k++, i++) {
        std::cin >> c;
        if(c == '*') {
            a[i] = INT_MIN;
            a[i-1]+=1;
            a[i+1]+=1;
            a[i-m-3]+=1;
            a[i-m-2]+=1;
            a[i-m-1]+=1;
            a[i+m+1]+=1;
            a[i+m+2]+=1;
            a[i+m+3]+=1;
        }
    }
    std::cin.ignore(256, '\n');
}

void shift(int from, int to, int* target) {
    for(int i = 0; from < to; from++, i++){
        target[i] = target[from];
        target[from] = 0;
    }
}

void print(int i, int j, int* a) {
    for(; i < j; i++) {
        if(a[i] < 0) {
            std::cout << "*";
        } else {
            std::cout << a[i];
        }
    }
    std::cout << std::endl;
}
