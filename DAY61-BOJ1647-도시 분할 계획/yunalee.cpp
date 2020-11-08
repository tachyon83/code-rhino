#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parent;

//간선 클래스
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	return false;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Edge> vc;
	cin >> N >> M;
	
	parent.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;	//현쟁 연결된 노드가 없으므로 자기자신이 부모
	}

	int n1, n2, dist;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> dist;
		vc.push_back(Edge(n1, n2, dist));	//간선정보 입력(노드1, 노드2, 비용)
	}

	//간선 비용을 기준으로 오름차순 정렬
	sort(vc.begin(), vc.end());

	int sum = 0;
	int prev = 0;
	for (int i = 0; i < vc.size(); i++) {
		//부모가 다른 경우(사이클이 발생하지 않는 경우)
		if (!findParent(vc[i].node[0], vc[i].node[1])) {
			sum += vc[i].distance;
			prev = vc[i].distance;
			unionParent(vc[i].node[0], vc[i].node[1]);
		}
	}

	cout << sum-prev << '\n';

	return 0;
}
