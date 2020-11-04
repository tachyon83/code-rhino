#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int dirR[8] = { -1,-1,0,1,1,1,0,-1 };
	int dirC[8] = { 0,1,1,1,0,-1,-1,-1 };
	vector<vector<int>> fireball(M, vector<int>(5, 0));
	for (int i = 0; i < M; i++) {
		cin >> fireball[i][0] >> fireball[i][1] >> fireball[i][2] >> fireball[i][3] >> fireball[i][4];
	}
	if (M == 0) {
		cout << 0;
		return 0;
	}

	for (int move = 0; move < K; move++) {
		//1.이동
		for (int i = 0; i < fireball.size(); i++) {
			fireball[i][0] = (fireball[i][0] + fireball[i][3] * dirR[fireball[i][4]] - 1 + N * 250) % N + 1;
			fireball[i][1] = (fireball[i][1] + fireball[i][3] * dirC[fireball[i][4]] - 1 + N * 250) % N + 1;
		}
		//2.합체와 분리
		sort(fireball.begin(), fireball.end());
		vector<int> needErase;
		int size = fireball.size();
		int start = 0;
		bool flag = true;
		int even = fireball[0][4] % 2;
		int num = 1;
		int totalM = fireball[0][2];
		int totalS = fireball[0][3];
		for (int i = 1; i <= size; i++) {
			if (i != size && fireball[i][0] == fireball[start][0] && fireball[i][1] == fireball[start][1]) {
				totalM += fireball[i][2];
				totalS += fireball[i][3];
				num++;
				if (flag == true && fireball[i][4] % 2 != even) {
					flag = false;
				}
			}
			else {
				if (num >= 2) {
					for (int j = start; j <= i - 1; j++) {
						needErase.push_back(j);
					}
					vector<int> tmp = { fireball[i - 1][0],fireball[i - 1][1],totalM / 5,totalS / num,0 };
					if (tmp[2] != 0) {
						if (flag == true) {
							tmp[4] = 0;
							fireball.push_back(tmp);
							tmp[4] = 2;
							fireball.push_back(tmp);
							tmp[4] = 4;
							fireball.push_back(tmp);
							tmp[4] = 6;
							fireball.push_back(tmp);
						}
						else {
							tmp[4] = 1;
							fireball.push_back(tmp);
							tmp[4] = 3;
							fireball.push_back(tmp);
							tmp[4] = 5;
							fireball.push_back(tmp);
							tmp[4] = 7;
							fireball.push_back(tmp);
						}
					}

				}
				if (i == size) {
					break;
				}
				start = i;
				totalM = fireball[i][2];
				totalS = fireball[i][3];
				num = 1;
				flag = true;
				even = fireball[i][4] % 2;
			}

		}
		for (int j = needErase.size() - 1; j >= 0; j--) {
			fireball.erase(fireball.begin() + needErase[j]);
		}
		needErase.clear();

	}
	int answer = 0;
	for (int i = 0; i < fireball.size(); i++) {
		answer += fireball[i][2];
	}
	cout << answer;
}



