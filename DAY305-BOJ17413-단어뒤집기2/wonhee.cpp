#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool c = false;
	string s,answer="";
	getline(cin,s);
	vector<char> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (c)
		{
			answer += s[i];
			if (s[i] == '>')
				c = false;
		}
		else if (s[i] == '<' || s[i]==' ')
		{
			while (!v.empty())
			{
				answer += v[v.size() - 1];
				v.pop_back();
			}
			answer += s[i];
			if(s[i]=='<')
				c = true;
		}
		else
			v.push_back(s[i]);
	}
	while (!v.empty())
	{
		answer += v[v.size() - 1];
		v.pop_back();
	}
	cout << answer;
	return 0;
}