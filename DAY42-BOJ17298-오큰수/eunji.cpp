#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int>arr(N, 0);
	vector <int>NGE(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i+1; j < N; j++) {
			if (arr[i] < arr[j]) {
				NGE[i] = arr[j];
				break;
			}
			else { 
				if (NGE[j] > arr[i]) {
					NGE[i] = NGE[j];
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i]<<" ";
	}
}
