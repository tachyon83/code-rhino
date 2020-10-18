#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N;
	vector<int> ans, arr;
	stack<int> st;

	cin >> N;
	arr.resize(N);
	ans.resize(N, -1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	st.push(0);
	for (int i = 1; i < N; i++)
	{
		if (st.empty())
			st.push(i);
		while (!st.empty() && arr[st.top()] < arr[i])
		{
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << ' ';
}