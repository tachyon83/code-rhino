#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int cost[10001]; // i번째 작업의 작업 소요 시간
int t[10001]; // i번째 작업이 끝나는 시간 기록
vector<int> v[10001]; // i번째 작업의 선행 작업 

int main()
{
	cin >> N;
	for (int cnt, i = 1; i <= N; i++) {
		cin >> cost[i];
		cin >> cnt; // i번째 작업의 선행 작업 개수
		for (int tmp, j = 1; j <= cnt; j++) {
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	for (int i = 1; i <= N; i++) {
		int cur = 0;
		for (int j = 0; j < v[i].size(); j++) // 현재 작업의 선행 작업 중 가장 늦게 끝나는 작업 시간 구하기
			cur = max(cur, t[v[i][j]]);
		t[i] = cur + cost[i];
	}

	int res = 0; //결과 구하기
	for (int i = 1; i <= N; i++) 
		res = max(res, t[i]);

	cout << res;
}
