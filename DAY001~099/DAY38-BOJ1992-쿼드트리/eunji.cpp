#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
void quardTree(vector<vector<int>> arr, int row, int col, int size);

int main() {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	quardTree(arr, 0, 0, N);
}

void quardTree(vector<vector<int>> arr,int row,int col,int size) {
	int tmp = arr[row][col];

	for (int i = row; i < size+row; i++) {
		for (int j = col; j < size+col; j++) {
			if (tmp != arr[i][j]) {
				printf("(");
				quardTree(arr, row, col, size / 2);
				quardTree(arr, row, col + size / 2,size/2);
				quardTree(arr, row + size / 2, col, size / 2);
				quardTree(arr, row + size / 2, col + size / 2, size / 2);
				printf(")");
				return;
			}
		}
	}
	printf("%d", tmp);
	return;
}
