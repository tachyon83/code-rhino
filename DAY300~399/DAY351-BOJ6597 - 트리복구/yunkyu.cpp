#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pre, in;
int inTree[26];

void post_order(int pre_left, int pre_right,int in_left,int in_right) {
	if (pre_left > pre_right) return; // left 가 right보다 큰 경우 종료

	char root = pre[pre_left]; // preorder에서 subtree의 root는 가장 왼쪽 노드
	int rootIdx = inTree[root - 'A']; // inorder에서의 root의 위치 
	/* 
	inorder root의 왼쪽은 left sub tree, inorder root의 오른쪽은 right sub tree 
	inorder에서 sub tree의 길이를 구해 preorder의 sub tree의 위치를 찾는다.
	*/
	post_order(pre_left + 1, pre_left + rootIdx - in_left, in_left, rootIdx - 1); 
	post_order(pre_left + rootIdx - in_left + 1, pre_right, rootIdx + 1, in_right); 
	cout << root; // post order이므로 가장 나중에 root 출력
}

int main() {
	while (cin >> pre >> in) {
		for (int i = 0; i < in.length(); i++) {
			int idx = in[i] - 'A';
			inTree[idx] = i;
		}
		post_order(0, pre.length() - 1, 0, in.length() - 1);
		cout << '\n';
	}

	return 0;
}
