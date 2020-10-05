#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool chkNum[10];
vector<char> chVc;
string MIN = "9879879879";
string MAX = "0";

void solution(int cnt, int k, string result) {
	if (cnt > k) {
		if (MIN > result) {
			MIN = result;
		}
		if (MAX < result) {
			MAX = result;
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		//숫자 사용 여부 체크
		if (!chkNum[i]) {
			if (cnt == 0) {	//첫번째 자리인 경우, 부등호 비교 없이 넣어줌
				result += (i + '0');
				chkNum[i] = true;	//사용
				solution(cnt + 1, k, result);
				chkNum[i] = false;	//사용 해제
				result.erase(result.size() - 1);	//마지막 자리를 다른 수로 교체하기 위해 지움
			}
			else {
				int len = result.size();
				int tmp = result[len - 1] - '0';
				if (chVc[cnt-1] == '>') {
					if (tmp > i) {
						result += (i + '0');
						chkNum[i] = true;
						solution(cnt+1, k, result);
						chkNum[i] = false;
						result.erase(result.size() - 1);
					}
				}
				else if (chVc[cnt-1] == '<') {
					if (tmp < i) {
						result += (i + '0');
						chkNum[i] = true;
						solution(cnt + 1, k, result);
						chkNum[i] = false;
						result.erase(result.size() - 1);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	char tmp;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		chVc.push_back(tmp);
	}
	solution(0, k, "");
	
	cout << MAX << '\n';
	cout << MIN << '\n';

	return 0;
}
