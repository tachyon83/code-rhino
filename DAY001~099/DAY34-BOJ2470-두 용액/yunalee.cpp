#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int left = 0;
	int right = n - 1;
		
	long long sum, lVal, rVal, result;
	result = arr[left] + arr[right];
	lVal = arr[left];
	rVal = arr[right];
	while (left < right) {
		sum = arr[left] + arr[right];
		if (abs(sum) < abs(result)) {
			result = abs(sum);
			lVal = arr[left];
			rVal = arr[right];
		}

		if (sum <= 0) {
			left++;
		}
		else {
			right--;
		}
	}
	
	cout << lVal << ' ' << rVal << '\n';

	return 0;

}
