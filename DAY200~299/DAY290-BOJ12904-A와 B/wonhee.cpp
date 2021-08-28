#include<iostream>
using namespace std;

bool bfs(string S, string T)
{
	int tSize = T.size();
	int d = T.size() - S.size();
	while (d--)
	{
		if (T[tSize - 1] == 'B')
		{
			tSize--;
			for (int i = 0; i < tSize / 2; i++)
			{
				if (T[i] == T[tSize - 1 - i])
					continue;
				int temp = T[i];
				T[i] = T[tSize - 1 - i];
				T[tSize - 1 - i] = temp;
			}
		}
		else
			tSize--;
	}
	for (int i = 0; i < S.size(); i++)
		if (S[i] != T[i])
			return false;
	return true;
}

int solution(string S, string T)
{
	if (bfs(S, T))
		return 1;
	return 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string S, T;
	cin >> S >> T;
	cout << solution(S, T);
	return 0;
}