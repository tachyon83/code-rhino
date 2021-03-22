#include<iostream>
#include<vector>
using namespace std;
int nums[20];
int N, S;
int num = 0;
void doDFS(int sum, int index);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		doDFS(0, i);
	}
	cout << num;
}

void doDFS(int sum, int index) {
	int s = sum + nums[index];
	if (s == S) num++;
	for (int i = index + 1; i < N; i++) {
		doDFS(s, i);
	}
}
