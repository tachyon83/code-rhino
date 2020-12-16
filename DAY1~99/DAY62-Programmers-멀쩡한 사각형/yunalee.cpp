#include <cmath>
#include <iostream>

using namespace std;

long long calc(long long w, long long h){
    long long div = w < h ? w : h;
    while(div > 0){
        if(w%div == 0 && h%div == 0){
            return div;
        }
        div--;
    }
    
    return 1;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;
    long long calcResult = calc(W, H);
    answer = W*H - (W + H -calcResult);
    
    return answer;
}
