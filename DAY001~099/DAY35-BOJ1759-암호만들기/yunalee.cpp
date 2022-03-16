#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[26];
bool chkArr[26];
string str;
vector<string> result;

void solution(int c, int n, int cnt, int start, int mCnt, int jCnt) {
	if (cnt == n) {
		if (mCnt >= 1 && jCnt >= 2) {
			result.push_back(str);
		}
		return;
	}

	for (int i = start; i < c; i++) {
		int idx = arr[i] - 'a';
		if (!chkArr[idx]) {
			str += arr[i];
			chkArr[idx] = true;
			
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				mCnt++;
			}
			else {
				jCnt++;
			}

			solution(c, n, cnt+1, i+1, mCnt, jCnt);
			chkArr[idx] = false;
			str.erase(str.size() - 1);

			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				mCnt--;
			}
			else {
				jCnt--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;
	
	char tmpCh;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + c);

	solution(c, n, 0, 0, 0, 0);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

}
