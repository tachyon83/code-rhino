#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		int num5 = N / 5;
		int temp = N % 5;
		if (temp == 0 && num5 < 5)
		{
			for (int j = 0; j < num5; j++)
				cout << 5;
			cout << '\n';
			continue;
		}
		int num3 = 0;
		while (num5 >= 0)
		{
			if (temp % 3 == 0)
			{
				num3 = temp / 3;
				break;
			}
			temp += 5;
			--num5;
		}
		if (num5 < 0)
		{
			cout << -1 << '\n';
			continue;
		}
		int totalNum = num5 + num3 - min(num5, num3);
		while (num5 > 0)
		{
			num5 -= 3;
			num3 += 5;
			if (totalNum > num5 + num3 - min(num5, num3))
				totalNum = num5 + num3 - min(num5, num3);
			else
			{
				if (totalNum < num5 + num3 - min(num5, num3))
				{
					num5 += 3;
					num3 -= 5;
				}
				break;
			}
		}

		for (int i = 0; i < num3 - min(num5, num3); i++)
			cout << 3;
		for (int i = 0; i < num5 - min(num5, num3); i++)
			cout << 5;
		for (int i = 0; i < min(num5, num3); i++)
			cout << 8;
		cout << '\n';
	}

	return 0;
}