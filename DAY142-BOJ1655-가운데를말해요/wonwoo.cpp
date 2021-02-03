#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);	cout.tie(0); ios_base::sync_with_stdio(false);
	int N, su, mid, i;
	priority_queue<int, vector<int>, less<int> > left;
	priority_queue<int, vector<int>, greater<int> > right;

	cin >> N;

	int arr[3];
	if (N >= 1)	{
		cin >> arr[0];
		cout << arr[0] << '\n';
		mid = arr[0];
	} if (N >= 2)	{
		cin >> arr[1];
		if (arr[1] < arr[0])
			mid = arr[1];
		cout << mid << '\n';
	} if (N >= 3)
	{
		cin >> arr[2];
		sort(arr, arr + 3);
		mid = arr[1];
		left.push(arr[0]);
		right.push(arr[2]);
		cout << mid << '\n';
	}

	for (int i = 4; i <= N; i++) {
		cin >> su;
		if (i % 2 == 0) {
			if (su == mid) {
				right.push(mid);
			} else if (su < mid) {
				right.push(mid);
				left.push(su);
				mid = left.top();
				left.pop();
			} else {
				right.push(su);
			}
		} else {
			int sizeL = left.size(), sizeR = right.size();
			if (su == mid) {
				if (sizeL < sizeR) {
					left.push(su);
				} else {
					right.push(su);
				}
			} else if (su < mid) {
				if (sizeL < sizeR) {
					left.push(su);
				} else {
					right.push(mid);
					int tmp = left.top();
					if (tmp <= su) {
						mid = su;
					} else {
						mid = tmp;
						left.pop();
						left.push(su);
					}
				}
			} else {
				if (sizeR < sizeL) {
					right.push(su);
				} else {
					left.push(mid);
					int tmp = right.top();
					if (tmp >= su) {
						mid = su;
					} else {
						mid = tmp;
						right.pop();
						right.push(su);
					}
				}
			}
		}
		cout << mid << '\n';
	}
}