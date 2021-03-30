//아직푸는중...
#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	cout << num(n, m);
}

int num(int n,int m) {
	return pow(10, n - m) - m;
}
