///LCD display
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110104&format=html
#include <iostream>
#include <cmath>
typedef void (*PrintDigitFunc) (char*, int, int, int);


void print(char*, int, int);
int getNumberChar(int);
void zero(char*, int, int, int);
void one(char*, int, int, int);
void two(char*, int, int, int);
void three(char*, int, int, int);
void four(char*, int, int, int);
void five(char*, int, int, int);
void six(char*, int, int, int);
void seven(char*, int, int, int);
void eight(char*, int, int, int);
void nine(char*, int, int, int);

int main(){
    int s, n, n0, i, j, hStep, vStep;
    char d[2392]; //8*(s+2+1)*(2*s+3) = 8*13*23
    PrintDigitFunc funcs[] = {zero, one, two, three, four, five, six, seven, eight, nine};
    while((std::cin>>s>>n) && s!=0) {
        n0 = getNumberChar(n);
        hStep = n0*(s+3);
        vStep = 2*s+3;   
        std::fill(d, d+hStep*vStep, 32);
        for(int i = 0; i < n0; i++){
            funcs[(n/(int)(std::pow(10, n0-i-1))) % 10](d, s, i*(s+3), hStep);
        }
        print(d, s, hStep);        
    }
    return 0;
}

int getNumberChar(int i){
    int j = 1;
    while((i/=10) != 0){
        j++;
    }
    return j;
}

void print(char* a, int s, int step){
    int from = 0;
    int until = step;
    s = 2*s+3;
    for(int s0 = 0; s0 < s; s0++){
        for(; from < until - 1; from++){
            std::cout << a[from];
        }
        from++;
        std::cout << '\n';
        until += step;
    }
    std::cout << '\n';   
}

void zero(char* a, int s, int p, int step){
    s++;
    int p0 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';
        a[(i+s)*step + p]='|';        
        a[p + i]='-';
        a[p0 + i]='-';
    }
}

void one(char* a, int s, int p, int step){
    s++;
    p += s;
    for(int i = 1; i < s; i++){
        a[i*step + p]='|';
        a[(i+s)*step + p]='|';
    }
}
void two(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p]='|';        
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}
void three(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}
void four(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';
        a[p0 + i]='-';
    }
}
void five(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';       
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}
void six(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';
        a[(i+s)*step + p]='|';        
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}
void seven(char* a, int s, int p, int step){
    s++;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[p + i]='-';
    }
}
void eight(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';
        a[(i+s)*step + p]='|';        
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}

void nine(char* a, int s, int p, int step){
    s++;
    int p0 = s*step + p;
    int p1 = (s<<1)*step + p;
    for(int i = 1; i < s; i++){
        a[i*step + p + s]='|';
        a[(i+s)*step + p + s]='|';
        a[i*step + p]='|';        
        a[p + i]='-';        
        a[p0 + i]='-';
        a[p1 + i]='-';
    }
}
