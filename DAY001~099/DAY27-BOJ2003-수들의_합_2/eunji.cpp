#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	//동적할당하면서 0으로 초기화
	int *A = (int *)calloc((N + 1), sizeof(int));
	int *B = (int*)calloc((N + 1), sizeof(int));

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	//start는 더할장소 (이미 합이 M이상이면 더할필요가 없기에 start 인덱스를 이용)
	//count는 합이 M이 될수 있을때 +1

	int start=1;
	int count = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = start; j <= i; j++) {
			B[j] += A[i];
			if (B[j] >= M) {
				start++;
				if (B[j] == M) {
					count++;
				}
			}
		}
	}

	cout << count;
}

