#include<iostream>
using namespace std;
int table[4001][4001] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int answer = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					table[i][j] = 1;
				else
					table[i][j] = table[i - 1][j - 1] + 1;
				answer = max(answer, table[i][j]);
			}
		}
	}
	cout << answer << '\n';
	return 0;
}