#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, H;
	cin >> N >> H;
	vector<int> seok(H + 1, 0);
	vector<int> jong(H + 1, 0);
	for (int i = 0; i < N / 2; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		seok[tmp1]++;
		jong[tmp2]++;
	}
	for (int i = H-1; i>0; i--) {
		seok[i] += seok[i+1];
		jong[i] += jong[i+1];
	}

	int min = 999999;
	int minNum = 0;
	for (int i = 1; i <= H; i++) {
		int val = seok[i]+jong[H-i+1];
		if (val <= min) {
			if (val == min) {
				minNum++;
			}
			else {
				min = val;
				minNum = 1;
			}
		}
	}
	cout << min <<" " <<minNum;
}
