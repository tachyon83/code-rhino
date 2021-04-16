#include<iostream>
using namespace std;
int map[1001];
int X = 1;
int N, M;
bool dice(int num);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
	for (int i = 1; i <= M; i++) {
		int tmp;
		cin >> tmp;
		if (dice(tmp) != 0) {
			cout << i;
			break;
		}
	}
}
bool dice(int num) {
	X += num;
	if (X >= N) return true;
	X += (map[X]);
	if (X >= N) return true;
	return false;

}
