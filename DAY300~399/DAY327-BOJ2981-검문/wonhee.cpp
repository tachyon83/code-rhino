#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int arr[101];

int gcd(int a, int b)
{
	return a % b ? gcd(b, a % b) : b;
}

int main()
{
	cin.tie(0);	cout.tie(0);
	cin.sync_with_stdio(0);
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);
	int dist = arr[1] - arr[0];
	for (int i = 1; i < N - 1; ++i)
		dist = gcd(dist, arr[i + 1] - arr[i]);

	vector<int> result;
	for (int i = 2; i <= sqrt(dist); i++){
		if (dist % i == 0){
			result.push_back(i);
			if (i != sqrt(dist))
				result.push_back(dist / i);
		}
	}
	result.push_back(dist);

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ' ';
	return 0;
}