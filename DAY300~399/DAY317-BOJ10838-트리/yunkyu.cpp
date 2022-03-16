#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
	int color;
	int parent;
};

Node tree[100001];
int check[100001];
int ch = 0;

int getLca(int a, int b) { 
	if (a == b) return a; // 같은 노드라면 노드가 lca

	ch++; // 노드 방문을 체크하기 위한 값
	int dist = 0;
	while (dist <= 1000) { // 거리가 1000이 최대이므로
		// root가 아니라면
		if (a != 0) {
			if (check[a] == ch) // 두 노드가 제일 처음 방문한 노드라면 lca임
				return a;
			check[a] = ch; // 방문 체크
			a = tree[a].parent; 
		}
		if (b != 0) {
			if (check[b] == ch)
				return b;
			check[b] = ch;
			b = tree[b].parent;
		}
		dist++; 
	}
	
	return 0; // 루트노드
}

void paint(int a, int b, int c) {
	int lca = getLca(a, b);
	int i;
	
	// lca까지 엣지의 색을 c로 변경
	while (a != lca) { 
		tree[a].color = c;
		a = tree[a].parent;
	}

	while (b != lca) {
		tree[b].color = c;
		b = tree[b].parent;
	}
}

void move(int a, int b) {
	tree[a].parent = b; // b의 child로 a노드를 이동
}

int count(int a, int b) {
	int lca = getLca(a, b);
	unordered_set<int> colors; // 색깔이 중복되지 않게 set이용

	while (a != lca) {
		colors.insert(tree[a].color);
		a = tree[a].parent;
	}

	while (b != lca) {
		colors.insert(tree[b].color);
		b = tree[b].parent;
	}

	return colors.size(); // 색의 가짓수를 반환
}

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	// tree[0] => root
	tree[0].color = 0;
	tree[0].parent = NULL;
	// root에 연결한다
	for (i = 1; i < n; i++) {
		tree[i].color = 0;
		tree[i].parent = 0;
	}

	for (i = 0; i < k; i++) {
		int r, a, b, c;
		scanf("%d %d %d", &r, &a, &b);
		switch (r) {
			case 1:
				scanf("%d", &c);
				paint(a, b, c);
				break;
			case 2:
				move(a, b);
				break;
			case 3:
				printf("%d\n", count(a, b));
		}
	}

	return 0;
}
