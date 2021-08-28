#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	int N; cin >> N;
	vector<string> in, out;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		in.push_back(s);
	}
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		out.push_back(s);
	}
	vector<string> swapping;

	int j = out.size() - 1, cnt = 0;
	for (int i = in.size() - 1; i >= 0; i--)
	{
		if (j < 0)
			break;

		while (!swapping.empty())
		{
			bool c = false;
			for (int k = 0; k < swapping.size(); k++)
			{
				if (out[j] == swapping[k])
				{
					--j;
					c = true;
					break;
				}
			}
			if (!c)
				break;
		}
		if (j < 0)
			break;

		if (in[i] == out[j])
			--j;
		else
			swapping.push_back(in[i]);
	}
	cout << swapping.size();
	return 0;
}