#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), cmp); // 끝나는 시간이 빠른순으로 정렬

	int cnt = 0;
	int end = 0;
	for (int i = 0; i < n; i++) {
		if (end <= v[i].first) { // 전의 회의가 끝난시간보다 현재 회의의 시작시간보다 크다면
			end = v[i].second; // 회의가 끝난시간 갱신
			cnt++; 
		}
	}

	printf("%d", cnt);
	return 0;
}
