//Interpreter
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110106&format=html
#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>

#define RAM 1000
#define REG 10

int run(int* ram, int* reg){
    int x0, x1, x2;
    int s = 1, i = 0;
    for(;; i++, s++){
        x0 = ram[i] / 100; x1 = (ram[i] / 10) % 10; x2 = ram[i] % 10;
        switch(x0){
            case 0:
                if(reg[x2] != 0) i = reg[x1] - 1;
                break;
            case 1:
                return s;
                break;
            case 2:
                reg[x1] = x2;
                break;
            case 3:
                reg[x1] = (reg[x1] + x2) % 1000;
                break;
            case 4:
                reg[x1] = (reg[x1] * x2) % 1000;
                break;
            case 5:
                reg[x1] = reg[x2];
                break;
            case 6:
                reg[x1] = (reg[x1] + reg[x2]) % 1000;
                break;
            case 7:
                reg[x1] = (reg[x1] * reg[x2]) % 1000;
                break;
            case 8:
                reg[x1] = ram[reg[x2]];
                break;
            case 9:
                ram[reg[x2]] = reg[x1];
                break;                    
        }        
    }
}

int main(){    
    std::string line;
    int n, x0, x1, x2, i, j = RAM;
    int ram[RAM];
    int reg[REG];
    std::fill(reg, reg + REG, 0);
    getline(std::cin, line);
    n = atoi(line.c_str());
    getline(std::cin, line);
    while(n-- > 0){
        i = 0;
        while(getline(std::cin, line) && !line.empty()) {
            ram[i++] = atoi(line.c_str());
        }
        if(j > i) std::fill(ram + i, ram + (j - i), 0);
        j = i;
        std::cout << run(ram, reg) << std::endl;
        if(n != 0) std::cout << std::endl;
    }
    return 0;
}

