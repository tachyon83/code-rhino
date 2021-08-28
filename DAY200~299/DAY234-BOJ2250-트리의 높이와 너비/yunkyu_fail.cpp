#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[10001];
bool hasParent[10001];
int col = 1;
int arr[10001];

void DFS(int curr,int length){
	int i;
	arr[curr] = col++;
	if (v[curr].size() == 0) return;

	int leftChild = v[curr][0];
	int rightChild = v[curr][1];
	if (leftChild != -1) {
		DFS(leftChild, length + 1);
	}
	if (rightChild != -1) {
		DFS(leftChild, length + 1);
	}
}

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		int par, left, right;
		scanf("%d %d %d", &par, &left, &right);
		v[par].push_back(left);
		v[par].push_back(right);
		if (left != -1) {
			hasParent[left] = true;
		}
		if (right != -1) {
			hasParent[right] = true;
		}
	}

	int root = 1;
	for (i = 1; i <= N; i++) {
		if (!hasParent[i])
			root = i;
	}

	DFS(root, 1);

	return 0;
}
