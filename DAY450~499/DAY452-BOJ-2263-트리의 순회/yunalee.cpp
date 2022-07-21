#include <iostream>
#include <vector>
using namespace std;

int N;
int inArr[100001];
int postArr[100001];
int arr[100001];
vector<int> vc;

void calc(int p_start, int p_end, int in_start, int in_end) {
	if (p_start > p_end || in_start > in_end) {
		return;
	}

	vc.push_back(postArr[p_end]);
	int tmp = arr[postArr[p_end]];
	int left = tmp - in_start;

	calc(p_start, p_start + left - 1, in_start, tmp - 1);
	calc(p_start + left, p_end - 1, tmp + 1, in_end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> inArr[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> postArr[i];
	}

	for (int i = 1; i <= N; i++) {
		arr[inArr[i]] = i;
	}

	calc(1, N, 1, N);
	
	for (int i = 0; i < N; i++) {
		cout << vc[i] << ' ';
	}
}
