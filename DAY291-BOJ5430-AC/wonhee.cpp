#include<iostream>
#include<deque>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	deque<int> dq;

	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		bool hasReversed = false;
		bool hasError = false;
		string p; cin >> p;
		int n; cin >> n;
		char a; cin >> a;
		int b;
		if (n == 0) cin >> a;
		else
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> b >> a;
				dq.push_back(b);
			}
		}
		int size = p.size();
		for (int j = 0; j < size; ++j)
		{
			if (p[j] == 'D')
			{
				if (dq.empty())
				{
					hasError = true;
					break;
				}
				if (hasReversed)
					dq.pop_back();
				else
					dq.pop_front();
			}
			else if (p[j] == 'R')
				hasReversed = !hasReversed;
		}

		if (hasError)
			cout << "error" << endl;
		else
		{
			cout << '[';
			if (!dq.empty())
			{
				if (hasReversed)
				{
					cout << dq.back();
					dq.pop_back();
					while (!dq.empty())
					{
						cout << ',' << dq.back();
						dq.pop_back();
					}
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
					while (!dq.empty())
					{
						cout << ',' << dq.front();
						dq.pop_front();
					}
				}
			}
			cout << ']' << endl;
		}
	}
	return 0;
}