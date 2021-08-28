#include<iostream>
#include<algorithm>
using namespace std;
int weight[1001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	sort(weight, weight + N);

	if (weight[0] != 1)
		cout << 1;
	else {
		long long sum = 1;
		for (int i = 1; i < N; i++)
		{
			if (sum + 1 >= weight[i])
				sum += weight[i];
			else
				break;
		}
		cout << sum + 1;
	}
	return 0;
}