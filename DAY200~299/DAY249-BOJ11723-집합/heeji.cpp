#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl "\n"

int board[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;

	while(m--) {
		//cout << m << endl;
		string temp_s;
		int temp;
		int result;
		cin >> temp_s;

		if (temp_s == "add") {
			cin >> temp;
			board[temp] = 1;
		}
		else if (temp_s == "remove") {
			cin >> temp;
			board[temp] = 0;
		}
		else if (temp_s == "check") {
			cin >> temp;
			if (board[temp] == 1) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (temp_s == "toggle") {
			cin >> temp;
			if (board[temp] == 1) board[temp] = 0;
			else board[temp] = 1;
		}
		else if (temp_s == "all") {
			for (int j = 0; j < 21; j++) {
				board[j] = 1;
			}
		}
		else {
			for (int j = 0; j < 21; j++) {
				board[j] = 0;
			}
		}
	}

	return 0;
}
