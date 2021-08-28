#include<iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		bool c[201][201] = { 0 };
		c[0][0] = 1;
		for (int i = 1; i <= s1.size(); ++i)	 c[i][0] = (s1[i - 1] == s3[i - 1]) ? c[i - 1][0] : 0;
		for (int i = 1; i <= s2.size(); ++i)	 c[0][i] = (s2[i - 1] == s3[i - 1]) ? c[0][i - 1] : 0;
		for (int i = 1; i <= s1.size(); ++i) {
			for (int j = 1; j <= s2.size(); ++j) {
				if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] != s3[i + j - 1]) c[i][j] = 0;
				else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1]) c[i][j] = c[i - 1][j];
				else if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) c[i][j] = c[i][j - 1];
				else c[i][j] = c[i - 1][j] || c[i][j - 1];
			}
		}
		cout << "Data set " << i+1 << ": ";
		(c[s1.size()][s2.size()]) ? cout << "yes\n" : cout << "no\n";
	}
	return 0;
}