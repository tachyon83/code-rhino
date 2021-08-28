#include<iostream>
using namespace std;
bool isNotPrime[10001] = { 0 };

int main()
{
	cin.tie(0);	cout.tie(0);
	cin.sync_with_stdio(0);
	isNotPrime[0] = 1;
	isNotPrime[1] = 1;
	for (int i = 2; i < 10000; i++)
	{
		if (isNotPrime[i] == 1)
			continue;
		int temp = 2;
		while (i * temp <= 10000)
		{
			isNotPrime[i * temp] = 1;
			temp++;
		}
	}

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		int n1 = N / 2, n2 = N - n1;
		while (true)
		{
			if (isNotPrime[n1] == 0 and isNotPrime[n2] == 0)
				break;
			n1--; n2++;
		}
		cout << n1 << ' ' << n2 << '\n';
	}
	return 0;
}