#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<int,int>> cube;
int ans = 0;
bool check = true;

void func(int length, int width, int height) {
	if (check == false) return;
	if (length == 0 || width == 0 || height == 0) { 
		return;
	}

	int i;

	for (i = n - 1; i >= 0; i--) { // 그리디하게 가장 큰 큐브부터 넣어봄
		if (cube[i].second <= 0) continue; // 큐브가 더 이상 없을때
		int l = cube[i].first;
		if (length < l || width < l || height < l) continue; // 큐브의 크기가 안들어갈때
		cube[i].second--;
		ans++;
		// 남은 공간에 대해 분할정복
		func(length, width, height - l);
		func(l, width - l, l);
		func(length - l, width, l);
		return;
	}
	
	check = false; // 남아있는 공간을 큐브로 채울 수 없을때

}

int main() {
	int l, w, h, i;
	scanf("%d %d %d", &l, &w, &h);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cube.push_back({ pow(2,a),b });
	}

	sort(cube.begin(),cube.end());

	func(l, w, h);
	
	if (check == false) printf("-1");
	else printf("%d", ans);

	return 0;
}
