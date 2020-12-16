#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<char>> vc(300);

void solution(int n) {
	int aLen = vc[n - 2].size();
	int bLen = vc[n - 1].size();
	
	int loop = aLen > bLen ? aLen : bLen;

	vector<char> tmpVc;
	for (int i = 0; i < loop; i++) {
		int aNum = aLen > i ? (vc[n - 2][i] - '0') * 2 : 0;
		int bNum = vc[n - 1][i] - '0';
		int sumTmp = aNum + bNum;
		
		if (tmpVc.size() >= i + 1) {
			int cNum = tmpVc[i] - '0';
			sumTmp += cNum;
		}

		int j = i;
		while (sumTmp / 10 > 0) {
			if (tmpVc.size() >= j + 1) {
				tmpVc[j] = (char)(sumTmp % 10 + '0');
			}
			else {
				tmpVc.push_back((char)(sumTmp % 10 + '0'));
			}
			j++;
			sumTmp /= 10;
		}

		if (tmpVc.size() >= j + 1) {
			tmpVc[j] = (char)(sumTmp % 10+'0');
		}
		else {
			tmpVc.push_back((char)(sumTmp % 10+'0'));
		}

	}

	vc[n] = tmpVc;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	vc[0].push_back('1');
	vc[1].push_back('1');
	vc[2].push_back('3');

	for (int i = 3; i < 300; i++) {
		solution(i);
	}
	
	while (scanf("%d", &n) > 0) {
		//cin >> n;
		for (int i = vc[n].size() - 1; i >= 0; i--) {
			cout << vc[n][i] - '0';
		}
		cout << '\n';
	}
}
