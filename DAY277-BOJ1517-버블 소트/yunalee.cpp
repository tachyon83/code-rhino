#include <iostream>
#include <vector>

using namespace std;

long long answer = 0;
int N;
vector<int> vc;

void solution(int start, int end) {
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	vector<int> tmp;

	if (start == end) {
		return;
	}

	solution(start, mid);
	solution(mid + 1, end);

	while (left <= mid && right <= end) {
		if (vc[left] <= vc[right]) {
			tmp.push_back(vc[left++]);
		}
		else {
			tmp.push_back(vc[right++]);
			answer += (mid + 1 - left);
		}
	}
	while (left <= mid) {
		tmp.push_back(vc[left++]);
	}
	while (right <= end) {
		tmp.push_back(vc[right++]);
	}
	for (int i = start, j = 0; i <= end; ++i, ++j) {
		vc[i] = tmp[j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		vc.push_back(a);
	}

	solution(0, N - 1);

	cout << answer << '\n';
}
