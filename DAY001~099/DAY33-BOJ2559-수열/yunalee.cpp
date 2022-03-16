#include <iostream>
using namespace std;

int arr[100100];
int Max = -987987987;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left, right;
	left = right = 0;

	int sum = 0;
	while (left <= right && right < n) {
		if (right - left + 1 < k) {
			sum += arr[right];
			right++;
			continue;
		}

		if (right - left + 1 == k) {
			sum += arr[right];
			if (Max < sum) {
				Max = sum;
			}

			right++;
			sum -= arr[left];
			left++;
		}
	}

	cout << Max << '\n';

}
