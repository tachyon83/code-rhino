#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, m;
string arr[10];
bool result = 0;
int y_ar[4] = { 0,1,0,-1 };
int x_ar[4] = { -1,0,1,0 };

void dfs(int cnt, int ry, int rx, int by, int bx) {
	if (cnt == 10)
		return;
	if (result)
		return;

	for (int i = 0; i < 4; i++) {

		int nry = ry, nrx = rx;
		int nby = by, nbx = bx;
		bool blue = false, red = false;
		while (1) {

			if (arr[nry + y_ar[i]][nrx + x_ar[i]] == '.') {
				nry += y_ar[i];
				nrx += x_ar[i];
			}
			else if (arr[nry + y_ar[i]][nrx + x_ar[i]] == 'O') {
				nry += y_ar[i];
				nrx += x_ar[i];
				red = true;
				break;
			}
			else if (arr[nry + y_ar[i]][nrx + x_ar[i]] == '#') {
				break;
			}
		}

		while (1) {
			if (arr[nby + y_ar[i]][nbx + x_ar[i]] == '.') {
				nby += y_ar[i];
				nbx += x_ar[i];
			}
			else if (arr[nby + y_ar[i]][nbx + x_ar[i]] == 'O') {
				nby += y_ar[i];
				nbx += x_ar[i];
				blue = true;
				break;
			}
			else if (arr[nby + y_ar[i]][nbx + x_ar[i]] == '#') {
				break;
			}
		}

		if (blue == true)
			continue;
		if (red == true) {
			result = true;
			return;
		}

		if (nrx == nbx && nry == nby) {			//포개진 경우
			if (i == 0) {
				if (rx > bx) 	nrx += 1;	//빨간공이 밑에 있었던 경우
				else			nbx += 1;
			}
			else if (i == 1) {
				if (ry > by)	nby -= 1;		//파란공이 더 왼쪽에서 시작한 경우
				else			nry -= 1;
			}
			else if (i == 2) {
				if (rx > bx)		nbx -= 1;		//파란공이 더 위에서 시작
				else				nrx -= 1;
			}
			else if (i == 3) {
				if (ry > by)		nry += 1;		//빨간공이 더 오른쪽에서 시작
				else				nby += 1;
			}
		}

		dfs(cnt + 1, nry, nrx, nby, nbx);




	}

}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	int ry, rx, by, bx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') {
				ry = i, rx = j;
				arr[i][j] = '.';
			}
			else if(arr[i][j] == 'B') {
				by = i, bx = j;
				arr[i][j] = '.';
			}
		}
	}

	dfs(0, ry, rx, by, bx);
	cout << result << endl;

	return 0;
}
