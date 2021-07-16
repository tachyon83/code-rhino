#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string S;
int M;
map<string, int> m;
vector<string> vc;
int pointArr[1001];

int solution(int num) {
	/* 입력된 문자열 탐색 시작 위치가 입력 문자열의 총 길이와 같거나 크다면
	 * 더 이상 탐색할 문자열이 없다는 것이므로 0 리턴 */
	if (num >= S.length()) {
		return 0;
	}

	if (pointArr[num] != 0) {
		return pointArr[num];
	}

	// 입력된 삭제 문자열 크기만큼 반복
	for (int i = 0; i < vc.size(); i++) {
		string key = vc[i];	//삭제문자열
		int point = m[key];	//삭제문자열 포인트

		/* num(탐색시작위치) + key.length()(삭제문자열 길이) <= S.length()(입력문자열 길이)
		 * 해당 식이 성립되어야 삭제문자열인지 파악이 된다
		 * num(탐색시작위치) + key.length()(삭제문자열 길이) 이 값이 더 크다면 삭제문자열을 찾기 전에
		 * 입력문자열이 끝난다 */
		bool tog = false;
		if (num + key.length() <= S.length()) {
			for (int j = 0; j < key.length(); j++) {
				if (key[j] != S[num + j]) {
					tog = true;
					break;
				}
			}

			//입력문자열에서 삭제문자열을 찾은 경우
			if (!tog) {
				pointArr[num] = max(pointArr[num], solution(num + key.length()) + point);
			}
		}
	}

	pointArr[num] = max(pointArr[num], solution(num + 1) + 1);

	return pointArr[num];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> M;
	
	string str_tmp;
	int int_tmp;
	for (int i = 0; i < M; i++) {
		cin >> str_tmp >> int_tmp;
		vc.push_back(str_tmp);
		m.insert({ str_tmp, int_tmp });
	}

	int answer = solution(0);

	cout << answer << '\n';
}
