//Australian Voting
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110108&format=html
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#define CND 20
#define BLT 1000

int getNames(std::string* names){
    std::getline(std::cin, names[0]);
    int n = atoi(names[0].c_str());
    for(int i = 0; i < n; i++) std::getline(std::cin, names[i]);
    return n;
}

int getVotes(int* votes, int n){
    int v = 0, j = 0;
    std::string line;
    while(std::getline(std::cin, line) && !line.empty()){
        v++;
        std::istringstream ss(line);
        for(int i = 0; i < n; i++){
            ss >> votes[j];
            votes[j++]--;
        }
    }
    return v;
}

void print(int* votes, int n, int v){
    for(int i = 0; i < v; i++){    
        for(int j = 0; j < n; j++)
            std::cout << votes[i*n + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void resolve(int* votes, int n, int v, int* maa){
    int sum[n];
    int mia[n];
    int start[v];
    int np, nma, nmi, mi, ma, s = n*v;
    std::fill(sum, sum + n, 0);
    for(int i = 0; i < v; i++){
        start[i] = i*n;
        sum[votes[start[i]]]++;
    }
    while(true){
        np = 0, nma = 0, nmi = 0, mi = v, ma = -1;
        for(int i = 0; i < n; i++){
            if(sum[i] == 0){
                for(int j = 0; j < s; j++) if(votes[j] == i) votes[j] = -1;
            } else {
                np++;
                if(sum[i] < mi){
                    mi = sum[i];
                    nmi = 0;
                    mia[nmi++] = i;
                } else if(sum[i] == mi){
                    mia[nmi++] = i;
                }
            }
            if(sum[i] > ma){
                ma = sum[i];
                nma = 0;
                maa[nma++] = i;
            } else if(sum[i] == ma){
                maa[nma++] = i;
            }
        }
        maa[nma] = -1;
        if((nma == 1 && int((float(sum[maa[0]])/v)*10) > 5) || np == nma) return;
        for(int i = 0; i < nmi; i++){
            for(int j = 0; j < s; j++) if(votes[j] == mia[i]) votes[j] = -1;
        }
        std::fill(sum, sum + n, 0);
        for(int i = 0; i < v; i++){
            while(votes[start[i]] == -1) start[i]++;
            sum[votes[start[i]]]++;
        }
    }
}

int main(){
    int n, v;
    int votes[BLT*CND];
    int sel[CND];
    std::string line;
    std::string names[CND];
    std::getline(std::cin, line);
    int m = atoi(line.c_str());
    std::getline(std::cin, line);
    while(m-- > 0){
        n = getNames(names);
        v = getVotes(votes, n);
        if(v==0){
            for(int i = 0; i < n; i++) std::cout << names[i] << std::endl;            
        } else {
            resolve(votes, n, v, sel);
            for(int i = 0; sel[i] != -1; i++) std::cout << names[sel[i]] << std::endl;
        }
        if(m != 0) std::cout << std::endl;                
    }
    return 0;    
}