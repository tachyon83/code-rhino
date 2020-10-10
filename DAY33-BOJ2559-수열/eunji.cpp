#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int N, K;
	cin >> N >> K;
	int sum = 0;
	int max = -10000000;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int num = 1;
	int start = -1;

	while (1) {
		if (start + num >= N) {
			break;
		}
		else if (num <=K) {
			sum += arr[start + (num)];
			if (num == K) {
				max = sum > max ? sum : max;
			}
			num++;
		}
		else {
			sum -= arr[++start];
			num--;
		}
	}

	cout << max;
}
