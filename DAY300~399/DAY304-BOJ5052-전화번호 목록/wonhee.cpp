#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		vector<string> v;
		int n; cin >> n;
		string s;
		bool isYes = true;
		for (int j = 0; j < n; ++j)
		{
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < n - 1; ++j)
		{
			if (v[j].size() >= v[j + 1].size())
				continue;
			if (v[j] == v[j + 1].substr(0, v[j].size()))
			{
				isYes = false;
				break;
			}
		}
		if (isYes)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}