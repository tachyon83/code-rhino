#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	bool arr[21];
	int K;
	int M;
	cin >> M;

	memset(arr, false, 21);
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "add") {
			cin >> K;
			if (!arr[K]) {
				arr[K] = true;
			}
		}
		else if (str == "remove") {
			cin >> K;
			if (arr[K]) {
				arr[K] = false;
			}
		}
		else if (str == "check") {
			cin >> K;
			if (arr[K]) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			cin >> K;
			if (arr[K]) {
				arr[K] = false;
			}
			else {
				arr[K] = true;
			}
		}
		else if (str == "all") {
			memset(arr, true, 21);
		}
		else if (str == "empty") {
			memset(arr, false, 21);
		}
	}
}
