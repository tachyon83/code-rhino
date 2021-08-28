#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> tree[11];

void getTree(int l, int r,int depth) {
	int root = (l + r) / 2; // 루트 노드
	tree[depth].push_back(v[root]);
	if (l == r) return; // 더 이상 child가 없다면 종료
	getTree(l, root - 1, depth + 1); // 왼쪽 sub tree로 진행
	getTree(root + 1, r, depth + 1); // 오른쪽 sub tree로 진행
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < pow(2, k) - 1; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	getTree(0, v.size() - 1, 1);
	for (int i = 1; i <= k; i++) { // 레벨이 i인 도시별로 출력
		for (int j = 0; j < tree[i].size(); j++) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}
	return 0;
}
