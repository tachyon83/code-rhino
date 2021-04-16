#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool compare(pair<string, int>& temp1, pair<string, int>& temp2) {
	return temp1.first < temp2.first;
}
int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	vector<string> s;
	vector<pair<string, int> > arr;
	int n, m;
	cin >> n >> m;

	s.resize(n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		arr[i].first = s[i];
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if ('A' <= q[0] && q[0] <= 'Z') {
			int left = 0;
			int right = n - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr[mid].first < q) {
					left = mid + 1;
				}
				else if (q < arr[mid].first) {
					right = mid - 1;
				}
				else {
					cout << arr[mid].second + 1;
					break;
				}
			}
		}
		else {
			int idx = stoi(q) - 1;
			cout << s[idx];
		}
		cout << '\n';
	}
}
