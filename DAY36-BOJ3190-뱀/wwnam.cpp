#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
vector<vector<int> > board;
vector<pair<int, char> > arrChange;
int N, K, L;
bool isValid(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}
void Moving(int x, int y)
{
	int ans = 0, idx = 0, dIdx = 0;
	int cur = arrChange[dIdx].first;
	deque<pair<int, int> > dq;
	dq.push_back(make_pair(x, y));
	board[x][y] = 2;

	while (1)
	{
		int cx = dq.front().first, cy = dq.front().second;
		int nx = cx + dir[dIdx][0], ny = cy + dir[dIdx][1];

		ans++;

		if (!isValid(nx, ny))
		{
			cout << ans << '\n';
			return;
		}
		else if (board[nx][ny] == 2)
		{
			cout << ans << '\n';
			return;
		}
		else if (board[nx][ny] == 1)
		{
			dq.push_front(make_pair(nx, ny));
			board[nx][ny] = 2;
		}
		else
		{
			dq.push_front(make_pair(nx, ny));
			board[nx][ny] = 2;
			board[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}

		if (ans == cur && L > idx)
		{
			if (arrChange[idx].second == 'D')
				dIdx = dIdx + 1 > 3 ? 0 : dIdx + 1;
			else if (arrChange[idx].second == 'L')
				dIdx = dIdx - 1 < 0 ? 3 : dIdx - 1;
			if (idx < L - 1)
				cur = arrChange[++idx].first;
		}
	}
	cout << ans << '\n';
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> K;
	board.resize(N + 1, vector<int>(N + 1, 0));

	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> L;
	arrChange.resize(L);
	for (int i = 0; i < L; i++)
		cin >> arrChange[i].first >> arrChange[i].second;

	Moving(1, 1);
}