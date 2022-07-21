using namespace std;

long long gcd(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
long long solution(int w,int h) {
    long long W = w;    
    long long H = h;
    long long tmp=(w+h)-gcd(w,h);
    
    return (W*H)-tmp;
}
