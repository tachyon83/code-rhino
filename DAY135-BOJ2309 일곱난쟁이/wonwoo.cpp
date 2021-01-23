#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> n(9);
	int i, j;
	for (i = 0; i < 9; i++) {
		cin >> n[i];
	}
	sort(n.begin(), n.end());

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)	{
			if (i == j) {
				continue;
			}
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) {
					continue;
				}
				sum += n[k];
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << n[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}