#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct transport {
	int start;
	int end;
	int capa;
};
bool compare(const struct transport a, const struct transport b)
{
	if (a.end < b.end)
		return true;
	else if (a.end == b.end)
		return a.start < b.start;
	else
		return false;
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, C, M, ans = 0, cur = 0;
	vector<struct transport> arr;
	vector<int> capacity;
	cin >> N >> C >> M;
	arr.resize(M);
	capacity.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
		cin >> arr[i].start >> arr[i].end >> arr[i].capa;

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < M; i++)
	{
		cur = 0;
		for (int j = arr[i].start; j < arr[i].end; j++)
			cur = max(cur, capacity[j]);

		int remain = min(arr[i].capa, C - cur);
		ans += remain;
		for (int j = arr[i].start; j < arr[i].end; j++)
			capacity[j] += remain;
	}
	cout << ans;
}