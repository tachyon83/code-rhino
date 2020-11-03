#include <vector>
#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> con(2 * N, 0);
	vector<bool> robot(N, 0);

	for (int i = 0; i <2*N;i++) {
		cin >> con[i];
	}

	int zeroNum = 0;
	int turn = 0;
	
	do{
		//1.벨트회전
		int tmp = con[2 * N - 1];
		for (int i = 2*N-1; i>0;i--) {
			con[i] = con[i - 1];
		}
		con[0] = tmp;
		for (int i = N - 1; i > 0; i--) {
			robot[i] = robot[i - 1];
		}
		robot[N - 1] = false;
		robot[0] = false;
		//2.로봇이동
		for (int i = N-2; i >= 0; i--) {
			if (robot[i] == true && con[i+1]>=1&&robot[i+1]==false) {
				if (--con[i + 1] == 0) {
					zeroNum++;
				}
				robot[i + 1] = robot[i];
				robot[i] = false;
			}
		}
		robot[N - 1] = false;
		//3.올라가는 위치에 로봇올리기
		if (robot[0] == false && con[0] >= 1) {
			robot[0] = true;
			if (--con[0] == 0) {
				zeroNum++;
			}
		}
		//단계증가
		turn++;
	}while (zeroNum < K);

	cout << turn;
	
}
