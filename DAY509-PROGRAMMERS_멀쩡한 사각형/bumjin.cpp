using namespace std;
#include <iostream>

long long  GCD(long long a,long long b){
	while(b!=0){
		long long r = a%b;
		a= b;
		b= r;
	}
	return a;
}  
long long solution(int w,int h){
    long long x=w;
    long long y=h;
    long long answer=1;
    long long unusedsquare=GCD(x,y);
    long long total=x*y;
  
    answer=total-(x+y);
    answer=answer+unusedsquare;
    return answer;
}
