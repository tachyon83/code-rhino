#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> box(1010);
vector<int> inBox(1010);

void solution(int n) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		inBox[i] = 1;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && inBox[j] + 1 > inBox[i]) {
				inBox[i] = inBox[j] + 1;
			}
		}
		result = max(result, inBox[i]);
	}

	cout << result << '\n';

	return 0;
}
