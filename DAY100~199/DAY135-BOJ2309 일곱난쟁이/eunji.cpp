#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> nan(9);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> nan[i];
		sum += nan[i];
	}
	sum -= 100;
	sort(nan.begin(), nan.end());
	int x, y;
	for (int i = 0; i < 9; i++) {
		x = nan[i];
		for (int j = i + 1; j < 9; j++) {
			y = nan[j];
			if (x + y == sum) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << nan[k] << endl;
				}
				return 0;
			}
		}
	}

}
