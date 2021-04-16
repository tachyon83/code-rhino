#include <iostream>
#include <vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> order(N, 0);
	vector<int> number(M, 0);

	//보드게임 칸의 명령어 입력
	for (int i = 0; i < N; i++){
		cin >> order[i];
	}

	//주사위 명령어 입력
	for (int i = 0; i < M; i++){
		cin >> number[i];
	}

	int result = 0;
	int now_pos = 0;
	for (int i = 0; i < M; i++){
		result++;
		now_pos += number[i];

		if (now_pos >= N){
			break;
		}

		now_pos += order[now_pos];
		if (now_pos >= N){
			break;
		}
	}

	cout << result << '\n';

	return 0;
}
