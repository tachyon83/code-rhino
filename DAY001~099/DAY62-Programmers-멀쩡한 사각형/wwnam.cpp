#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
long long solution(int w, int h)
{
    long long answer = 0;
    int g = gcd(w, h);

    answer = (long long)w * h;
    answer = answer - (w + h - g);
    return answer;
}