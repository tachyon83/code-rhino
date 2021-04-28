#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};
vector<int> v;

Node* add(Node *node ,int n) {
	if (node == NULL) { // 노드가 없다면 생성하여 준다
		node = new Node();
		node->key = n;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (n < node->key) { // 부모 노드의 키보다 작다면 왼쪽으로
		node->left = add(node->left, n); 
	}
	else { // 부모 노드의 키보다 작다면 오른쪽으로
		node->right = add(node->right, n);
	}

	return node;
}

void postOrder(Node* node) { // left -> right -> root
	if(node->left != NULL) // left child가 있다면 왼쪽으로
		postOrder(node->left);
	if (node->right != NULL) // right child가 있다면 오른쪽으로
		postOrder(node->right);

	printf("%d\n", node->key); // 루트 key 표시
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i = 0, n;
	Node* parent = NULL; // 루트 노드
	while (cin >> n) {
		v.push_back(n);
		parent = add(parent, n); // 트리 생성
	}

	postOrder(parent);

	return 0;
}
