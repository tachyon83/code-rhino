#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

bool visited[201][201];

bool verify(string s1, string s2, string s3) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int i = q.front().first.first;
		int j = q.front().first.second;
		int a = q.front().second;
		q.pop();

		if (i == s1.length() && j == s2.length()) return true; // 문자열을 전부 찾았다면
		
		if (i < s1.length() && s1[i] == s3[a] && !visited[i + 1][j]) { 
			q.push({ {i + 1,j}, a + 1 });
			visited[i + 1][j] = true;
		}
		if (j < s2.length() && s2[j] == s3[a] && !visited[i][j + 1]) {
			q.push({ {i ,j + 1}, a + 1 });
			visited[i][j + 1] = true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i;
	int n;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		if (verify(s1, s2, s3)) {
			cout << "Data set " << i + 1 << ": yes" << "\n";
		}
		else {
			cout << "Data set " << i + 1 << ": no" << "\n";
		}
	}
	return 0;
}
