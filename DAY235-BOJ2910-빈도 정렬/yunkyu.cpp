#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int,pair<int,int>> mp; // pair 첫번째 = 빈도수 두번째 = 나온 순서
vector<int> v;

bool cmp(int& a, int& b) {
	if (mp[a].first == mp[b].first) // 빈도수가 같다면 먼저 나온 순으로
		return mp[a].second < mp[b].second;
	return mp[a].first > mp[b].first;
}
int main() {
	int N, C, i;
	scanf("%d %d", &N, &C);
	for (i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
		mp[a].first ++; // 빈도수
		if (mp[a].second == 0) // 처음 나왔다면 순서를 기록
			mp[a].second = i;
	}

	sort(v.begin(), v.end(),cmp); // 정렬

	for(i=0; i<N; i++)
		printf("%d ", v[i]);

	return 0;
}
