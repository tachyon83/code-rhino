#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

void findFriend(string f1, string f2, vector < vector<string>> &arr);

int main() {
	int N;
	int F;


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> F;
		vector <vector<string>> arr(0, vector<string>(0));
		for (int j = 0; j < F; j++) {
			string f1, f2;
			cin >> f1 >> f2;
			findFriend(f1, f2,arr);
		}
	}
}

void findFriend(string f1, string f2, vector<vector<string>> &arr) {
	int f1index = -1;
	int f2index = -1;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (f1index != -1 && f2index != -1) {
				//goto 문은 또 처음써보네...산으로 가는 코딩..
				goto EXIT;
			}
			if (f1index == -1 && !(arr[i][j].compare(f1))) {
				f1index = i;
			}
			else if (f2index == -1 && !(arr[i][j].compare(f2))) {
				f2index = i;
			}

		}
	}

EXIT:
	//f1이 없다.
	if (f1index == -1) {
		//f2도 없으면 새로삽입
		if (f2index == -1) {
			vector<string> brr(2);
			brr[0] = f1;
			brr[1] = f2;
			arr.push_back(brr);
			cout << brr.size() << endl;
		}
		//f2 있으면 f2쪽에 f1만 삽입
		else {
			arr[f2index].push_back(f1);
			cout << arr[f2index].size() << endl;
		}
	}
	//f1이 있다.
	else {
		//f2 없으면 f2를 f1에 삽입
		if (f2index == -1) {
			arr[f1index].push_back(f2);
			cout << arr[f1index].size() << endl;
		}
		//둘다 잇으면 두개 이어줌
		else {
			if (f1index != f2index) {
				vector<string> temp;
				temp.assign(arr[f2index].begin(), arr[f2index].end());
				arr[f1index].insert(arr[f1index].end(), temp.begin(), temp.end());
				arr.erase(arr.begin() + f2index);

				cout << arr[f1index].size() << endl;

			}

		}
	}
}
