//Check The Check
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110107&format=html
#include <iostream>
#include <cmath>

bool readTable(char* t, int& k, int& K){
    char c;
    k = K;
    for(int i = 0; i < 8; i++){
        for(int j = 12*i + 2, j0 = j + 8; j < j0; j++){
            while(std::cin.get(c) && isspace(c));
            t[j] = c;
            if(c=='k') k = j;
            if(c=='K') K = j;    
        }
    }
    return k != K;
}

bool knight(int j, int k){
    return std::abs(k-j) == 14 || std::abs(k-j) == 10 || std::abs(k-j) == 25 || std::abs(k-j) == 23;
}

bool rook(int j, int k, char* a){
    int x = j;
    int x0 = x/12;
    if((k/12) == x0){
        x0 *= 12;
        if(k > j){
            x0+=10;
            while(++x < x0 && a[x]=='.');
	    } else {
            x0+= 2;    
            while(--x >= x0 && a[x]=='.');
        }
    }
    if((k%12) == j%12){
        if(k > j){
            while((x+=12) < 96 && a[x]=='.');
        } else {
            while((x-=12) > 0 && a[x]=='.');
        }
    }
    return x == k;
}

bool bishop(int j, int k, char* a){
    for(int x = j-13; x>0 && x%12>1; x-=13)
        if(a[x] != '.'){
            if(k == x) return true;
            break;
        }
    
    for(int x = j+13; x<96 && x%12<10; x+=13)
        if(a[x] != '.'){
            if(k == x) return true;
            break;
        }
    
    for(int x = j-11; x>0 && x%12<10; x-=11)
        if(a[x] != '.'){
            if(k == x) return true;
            break;
        }
    
    for(int x = j+11; x<96 && x%12>1; x+=11)
        if(a[x] != '.'){
            if(k == x) return true;
            break;
        }
    
    return false;
}

int main(){
    int g = 1;
    int k, K, s, x, x0;
    char a[96];
    std::fill(a,a+96,'.');
    while(readTable(a, k, K)){
        s = 0;
        for(int i = 0; i < 8 && s == 0; i++){
            for(int j = 12*i + 2, j0 = j + 8; j < j0; j++){
                switch(a[j]){
                    case '.':
                    case 'k':
                    case 'K':
                        continue;
                    case 'p':
                        if(K == (j + 11) || K == (j + 13)) s =-1; 
                        break;
                    case 'P':
                        if(k == (j - 13) || k == (j - 11)) s = 1;
                        break;
                    case 'n':
                        if(knight(j, K)) s =-1;
                        break;
                    case 'N':
                        if(knight(j, k)) s = 1;
                        break;
                    case 'r':
                        if(rook(j, K, a)) s =-1;
                        break;
                    case 'R':
                        if(rook(j, k, a)) s = 1;
                        break;
                    case 'b':
                        if(bishop(j, K, a)) s =-1;
                        break;
                    case 'B':
                        if(bishop(j, k, a)) s = 1;
                        break;
                    case 'q':
                        if(bishop(j, K, a) || rook(j, K, a)) s =-1;
                        break;
                    case 'Q':
                        if(bishop(j, k, a) || rook(j, k, a)) s = 1;
                        break;
                }
            }
        }
        switch(s){
            case -1:
                std::cout << "Game #" << g++ << ": white king is in check." << std::endl;
                break;
            case  0:
                std::cout << "Game #" << g++ << ": no king is in check." << std::endl;
                break;
            case  1:
                std::cout << "Game #" << g++ << ": black king is in check." << std::endl;
                break;
        }
    }
    return 0;
}