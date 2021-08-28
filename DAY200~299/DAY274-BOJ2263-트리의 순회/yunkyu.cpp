#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void preorder(vector<int> &inorder, vector<int> &postorder, vector<int> &index , int inLeft , int inRight, int postLeft, int postRight) {
	if (inLeft > inRight || postLeft > postRight) return; // 왼쪽끝이 오른쪽끝을 넘어서면 종료
	int root = postorder[postRight]; // 후위 순회의 마지막 값이 루트
	printf("%d ", root); 
	int rootIndex = index[root]; // 전위순회에서 루트의 인덱스

	preorder(inorder, postorder, index, inLeft , rootIndex - 1, postLeft, postLeft + rootIndex - inLeft - 1); // 왼쪽 서브트리
	preorder(inorder, postorder, index, rootIndex + 1, inRight, postLeft + rootIndex - inLeft , postRight -1); // 오른쪽 서브트리
}

int main() {
	int n, i, j;
	scanf("%d", &n);

	vector<int> postorder(n);
	vector<int> inorder(n);
	vector<int> index(n+1);

	for (i = 0; i < n; i++) {
		scanf("%d", &inorder[i]);
		index[inorder[i]] = i; // 전위 순회 값들에 대한 인덱스 저장
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &postorder[i]);
	}
	preorder(inorder, postorder, index, 0, n - 1, 0, n - 1);
	return 0;
}
