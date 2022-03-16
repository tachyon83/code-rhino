#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
  
	int M = key[0].size();
	int N = lock[0].size();
	vector<vector<int>> arr;
	arr.assign((M - 1) * 2 + N, vector<int>((M - 1) * 2 + N, 0));
	vector<vector<int>> arr1;
	arr1.assign((M - 1) * 2 + N, vector<int>((M - 1) * 2 + N, 0));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i + M - 1][j + M - 1] = lock[i][j];
		}
	}

	for (int rotate = 0; rotate < 4; rotate++) {
		vector<vector<int>> rotkey;
		rotkey.assign(M, vector<int>(M, 0));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				rotkey[j][M - 1 - i] = key[i][j];
			}
		}
		key = rotkey;

		for (int i = 0; i < M - 1 + N; i++) {
			for (int j = 0; j < M - 1 + N; j++) {

				for (int k = 0; k < 2 * (M - 1) + N; k++) {
					for (int h = 0; h < 2 * (M - 1) + N; h++) {
						arr1[k][h] = arr[k][h];
					}
				}

				for (int k = 0; k < M; k++) {
					for (int h = 0; h < M; h++) {
						if (key[k][h] == 1) {
							arr1[i + k][j + h] += rotkey[k][h];
						}
					}
				}

				for (int k = 0; k < N; k++) {
					for (int h = 0; h < N; h++) {
						if (arr[k + M - 1][h + M - 1] == 1) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}