//수정중
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int count(int x, int n);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, k;
	cin >> N >> k;
	int start = 1;
	int end = N * N;
	int mid = start;
	while (mid < end) {
		mid = (start + end) / 2;
		if (count(mid,N) < k) start = mid;
		else end = mid - 1;
	}
	return mid;

}

int count(int x,int n) {
	int num = 0;
	int i = n > x ? x : n;
	int tmp;
	for (; i >= 1; i--) {
		int tmp =x/i; 
		num += (x / i) * 2;
	}
	if ((double)i == tmp) num++;
	return num;
}
