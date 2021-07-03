#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> makeTable(string s)
{
	int size = s.size();
	vector<int> table(size, 0);
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = table[j - 1];
		if (s[i] == s[j])
			table[i] = ++j;
	}
	return table;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; long long N;
	cin >> s >> N;
	vector<int> table = makeTable(s);
	long long pivot = table[table.size() - 1];
	long long ret = N * (table.size() - table[table.size() - 1]) + table[table.size() - 1];

	cout << ret;
	return 0;
}