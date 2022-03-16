#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
vector<int> r;
vector<pair<int, int> > parent;
int findSet(int id)
{
	if (id == parent[id].first)
		return id;
	return parent[id].first = findSet(parent[id].first);
}
void unionSet(int x, int y)
{
	x = findSet(x), y = findSet(y);
	if (x == y)
	{
		cout << parent[x].second << '\n';
		return;
	}
	if (r[x] < r[y])
		swap(x, y);

	parent[y].first = x;
	if (r[x] == r[y])
		r[x]++;
	parent[x].second += parent[y].second;
	cout << parent[x].second << '\n';
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int T;
	string str1, str2;

	cin >> T;
	while (T--)
	{
		unordered_map<string, int> userMap;
		r.clear(); parent.clear();
		int F, id = 1;
		cin >> F;

		parent.resize(F * 3);
		r.resize(F * 3);

		for (int i = 0; i < F; i++)
		{
			cin >> str1 >> str2;
			if (userMap[str1] == 0)
			{
				parent[id] = make_pair(id, 1);
				r[id] = 1;
				userMap[str1] = id++;
			}
			if (userMap[str2] == 0)
			{
				parent[id] = make_pair(id, 1);
				r[id] = 1;
				userMap[str2] = id++;
			}

			unionSet(userMap[str1], userMap[str2]);
		}
	}
}