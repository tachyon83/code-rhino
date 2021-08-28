#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;

void preorder(char root) { // 현재 노드 출력하고 left child부터 방문 후에 right child로 방문
	cout << root; 

	if (tree[root].first != '.') 
		preorder(tree[root].first);

	if (tree[root].second != '.') 
		preorder(tree[root].second);

	return;
}

void inorder(char root) { // left child부터 방문 후에 현재 노드 출력하고 right child로 방문
	if (tree[root].first != '.')
		inorder(tree[root].first);

	cout << root;

	if (tree[root].second != '.')
		inorder(tree[root].second);
	return;
}

void postorder(char root) { // left child부터 방문 후에 right child로 방문하고 현재 노드 출력
	if (tree[root].first != '.')
		postorder(tree[root].first);

	if (tree[root].second != '.')
		postorder(tree[root].second);

	cout << root;
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a] = { b,c }; // 맵으로 트리 생성
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	return 0;
}
