#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main3() {
	int N;
	cin >> N;
	vector <int> rope(N);
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end());
	for (int i = 0; i < N; i++) {
		rope[i] *= (N - i);
	}
	int max = *max_element(rope.begin(), rope.end());
	cout << max;
	return 0;
}
