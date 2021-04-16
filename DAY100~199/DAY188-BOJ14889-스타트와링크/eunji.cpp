#include<iostream>
int table[21][21] = { 0, };
int N;
int degree = 987654321;
using namespace std;
void doBT(int start, int depth);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
		}
	}
	doBT(1, 0);
	cout << degree;

}

void doBT(int start, int depth) {
	if (depth == (N / 2)) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 1; i <= N; i++) {
			if (table[i][i]) {
				for (int j = i + 1; j <= N; j++) {
					if (table[j][j]) {
						sum2 += (table[i][j] + table[j][i]);
					}
				}
			}
			else {
				for (int j = i + 1; j <= N; j++) {
					if (!table[j][j]) {
						sum1 += (table[i][j] + table[j][i]);
					}
				}
			}
		}
		int ans = abs(sum1 - sum2);
		degree = ans < degree ? ans : degree;
		return;
	}
	else {

		for (int i = start; i <= N; i++) {
			if (!table[i][i]) {
				table[i][i] = 1;
				doBT(i + 1, depth + 1);
				table[i][i] = 0;
			}
		}
	}

}
