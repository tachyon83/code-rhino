#include <iostream>
#include <queue>
using namespace std;
void doEscape(vector<vector<char>> map, queue<pair<int, int>> fire, int strow, int stcol, int h, int w);
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		int strow, stcol;
		//char map[1000][1000] = { 0, };
		int w, h;
		cin >> w >> h;
		vector<vector<char>> map(h, vector<char>(w, 0));
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				cin >> map[r][c];
				if (map[r][c] == '@') {
					strow = r;
					stcol = c;
				}
				else if (map[r][c] == '*') {
					q.push(make_pair(r, c));
				}
			}
		}
		doEscape(map, q, strow, stcol, h, w);

	}
}

void doEscape(vector<vector<char>> map, queue<pair<int, int>> fire, int strow, int stcol, int h, int w) {
	int dirR[4] = { 0,1,0,-1 };
	int dirC[4] = { 1,0,-1,0 };
	bool visit[1000][1000] = { 0, };
	visit[strow][stcol] = true;
	queue<pair<int, int>> sg;
	sg.push({ strow, stcol });
	int time = 0;
	while (++time) {
		int firenum = fire.size();
		//불 각각마다 불 옮김
		for (int i = 0; i < firenum; i++) {
			int row = fire.front().first;
			int col = fire.front().second;
			fire.pop();
			for (int d = 0; d < 4; d++) {
				int rr = row + dirR[d];
				int cc = col + dirC[d];
				if (rr < h && rr >= 0 && cc < w && cc >= 0 && (map[rr][cc] == '.' || map[rr][cc] == '@')) {
					map[rr][cc] = '*';
					fire.push({ rr, cc });
				}
			}
		}
		int sgnum = sg.size();
		//상근 옮김
		for (int i = 0; i < sgnum; i++) {
			int row = sg.front().first;
			int col = sg.front().second;
			sg.pop();
			for (int d = 0; d < 4; d++) {
				int rr = row + dirR[d];
				int cc = col + dirC[d];
				if (rr < 0 || rr >= h || cc < 0 || cc >= w) {
					cout << time << endl;
					return;
				}
				else if (map[rr][cc] == '.' && visit[rr][cc] == false) {
					visit[rr][cc] = true;
					sg.push({ rr, cc });
				}
			}

		}
		if (sg.empty()) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}

	}
}
