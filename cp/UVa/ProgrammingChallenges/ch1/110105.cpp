//Graphical Editor
//http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110105&format=html
#include <iostream>
#include <stack>
#define MAX 250

int main(){
    char p[MAX*MAX];
    char f[MAX];
    char c, c0;
    int m, n, n0, n1, m0, m1, i0, i1;
    std::stack<int> s;
    while(true){
        std::cin >> c;
        switch(c){
            case 'I':
                std::cin >> m >> n;
            case 'C':
                std::fill(p, p + m*n, 'O');
                break;
            case 'L':
                std::cin >> m0 >> n0 >> c;
                m0--; n0--;
                p[m*n0 + m0] = c;
                break;
            case 'V':
                std::cin >> m0 >> n0 >> n1 >> c;
                if(n0 > n1) std::swap(n0, n1);
                m0--; n0--; n1--;
                n0 = m*n0 + m0;
                n1 = m*n1 + m0;
                for(; n0 <= n1; n0 += m) p[n0] = c;
                break;
            case 'H':
                std::cin >> m0 >> m1 >> n0 >> c;
                if(m0 > m1) std::swap(m0, m1);
                m0--; m1--; n0--;
                m0 = m*n0 + m0;
                m1 = m*n0 + m1;
                for(; m0 <= m1; m0++) p[m0] = c;
                break;
            case 'K':
                std::cin >> m0 >> n0 >> m1 >> n1 >> c;
                if(n0 > n1) std::swap(n0, n1);
                if(m0 > m1) std::swap(m0, m1);
                m0--; m1--; n0--; n1--;
                for(; n0<=n1; n0++) for(i0 = m*n0 + m0, i1 = m*n0 + m1; i0 <= i1; i0++) p[i0] = c;
                break;
            case 'F':
                std::cin >> m0 >> n0 >> c;
                m0--; n0--;
                i0 = m*n0 + m0;
                c0 = p[i0];
                if(c0 == c) continue;
                s.push(i0);
                while(!s.empty()){
                    i0 = s.top();
                    s.pop();
                    if(p[i0] == c0){
                        p[i0] = c;
                        if(i0 % m != 0){
                            s.push(i0-1);
                        }
                        if((i0 + 1) % m != 0){
                            s.push(i0 + 1);
                        }
                        if(i0 - m >= 0){
                            s.push(i0-m);
                        }
                        if(i0 + m < m*n){
                            s.push(i0+m);
                        }
                    }
                }
                break;
            case 'S':
                std::cin >> f;
                std::cout << f << std::endl;
                for(n0 = 0, m0 = 0, m1 = 0; n0 < n; n0++){
                    for(m1 += m; m0 < m1; m0++) std::cout << p[m0];
                    std::cout << std::endl;
                }
                break;
            case 'X':
                return 0;
        }
    }
}