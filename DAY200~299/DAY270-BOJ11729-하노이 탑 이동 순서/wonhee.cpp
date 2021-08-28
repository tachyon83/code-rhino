#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> v;

void print()
{
	int size = v.size();
	cout << size << '\n';
	for (int i = 0; i < size; ++i)
		cout << v[i].first << ' ' << v[i].second << '\n';
}

void hanoiTop(int num, int from, int to, int by)
{
	if (num == 1)
	{
		v.push_back({ from, by });
		return;
	}

	hanoiTop(num - 1, from, by, to);
	v.push_back({ from, by });
	hanoiTop(num - 1, to, from, by);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	hanoiTop(N, 1, 2, 3);
	print();

	return 0;
}