#include <iostream>
using namespace std;

int a[20] = { 0 }, ans = 0;
bool isPossible = true;

void solution(int l, int w, int h) 
{
	if ((l > 0) && (w > 0) && (h > 0)) 
	{
		int i;
		for (i = 19; i >= 0; i--) 
		{
			int cur = 1 << i;
			if ((a[i] > 0) && (l >= cur) && (w >= cur) && (h >= cur)) {

				a[i] -= 1;
				ans += 1;
				solution(l, w, h - cur);
				solution(l - cur, cur, cur);
				solution(l, w - cur, cur);
				break;
			}
		}
		if (i == -1)
			isPossible = false;
	}
}

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int l, w, h;
	cin >> l >> w >> h;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		int x, y;
		cin >> x >> y;
		a[x] = y;
	}
	solution(l, w, h);
	cout << (isPossible? ans : -1);
	return 0;
}