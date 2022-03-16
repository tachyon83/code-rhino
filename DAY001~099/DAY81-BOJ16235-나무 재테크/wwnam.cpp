#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool isValid(int y, int x, const int N) {
	return y >= 0 && y < N && x >= 0 && x < N;
}
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	const int MAX_AGE = 10;
	int dir[8][2] = {
		{1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1}
	};

	int N, M, K;
	vector<vector<int> > arr;
	vector<vector<int> > nutri;
	vector<vector<vector<int> > > plant;

	cin >> N >> M >> K;
	arr.resize(N, vector<int>(N));
	nutri.resize(N, vector<int>(N));
	plant.resize(N, vector<vector<int> >(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> nutri[i][j];
			arr[i][j] = 5;
		}
	}

	int y, x, age;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> age;
		plant[y - 1][x - 1].push_back(age);
	}

	while (K--) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int numPlant = plant[y][x].size();
				if (numPlant) {
					int dead = 0;
					vector<int> tmpArr;

					sort(plant[y][x].begin(), plant[y][x].end());
					for (int i = 0; i < numPlant; i++) {
						int age = plant[y][x][i];
						if (arr[y][x] >= age) {
							arr[y][x] -= age;
							tmpArr.push_back(age + 1);
						}
						else {
							dead += age / 2;
						}
					}

					plant[y][x].clear();
					int tmpSize = tmpArr.size();
					for (int i = 0; i < tmpSize; i++) {
						plant[y][x].push_back(tmpArr[i]);
					}

					arr[y][x] += dead;
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int numPlant = plant[y][x].size();
				if (numPlant) {
					for (int i = 0; i < numPlant; i++) {
						int age = plant[y][x][i];

						if (age % 5 == 0) {
							for (int d = 0; d < 8; d++) {
								int ny = y + dir[d][0];
								int nx = x + dir[d][1];

								if (isValid(ny, nx, N)) {
									plant[ny][nx].push_back(1);
								}
							}
						}
					}
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				arr[y][x] += nutri[y][x];
			}
		}
	}

	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			ans += plant[y][x].size();
		}
	}

	cout << ans << '\n';
}