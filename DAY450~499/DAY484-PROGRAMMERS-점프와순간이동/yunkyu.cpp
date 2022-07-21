#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n > 0) {
        if(n % 2 != 0) { // 홀수면 한칸 점프
            n--;
            ans++;
        }
        else n /= 2; // 짝수면 순간이동
    }

    return ans;
}
