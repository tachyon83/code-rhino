#include <iostream>

using namespace std;
int countday(int out, int use[], int N);

int main() {
	int N, M;
	int start=0;
	int end = 1000000000;
	int mid;
	cin >> N >> M;
	int use[100001] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> use[i];
		start = start < use[i] ? use[i] : start;
	}

	while (start<=end) {
		mid = (start + end) / 2;
		int count = countday(mid, use, N);
		if (count == M) {
			while (1) {
				mid--;
				count=countday(mid, use, N);
				if (count != M) {
					mid++;
					break;
				}
			}
			break;
		}
		else if (count > M){
		start = mid + 1;

		}
		else {
			end = mid - 1;
		}
	}
	cout << mid;
}

int countday(int out, int use[],int N) {
	int have = 0;
	int count = 0;;
	for (int i = 0; i < N; i++) {
		if (have < use[i]) {
			have = out;
			count++;
		}
			have -= use[i];
	}
	return count;
}
