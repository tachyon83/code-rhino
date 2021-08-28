#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, pair<int, int>>> vc;
int p[301];

int getParent(int x) {
	if (p[x] == x) {
		return x;
	}

	return p[x] = getParent(p[x]);
}

// 각 부모 노드를 합친다
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	// 작은 노드를 부모로 합친다
	if (a < b) {
		p[b] = a;
	}
	else if(a > b) {
		p[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		vc.push_back({ tmp,{i,0} });
		p[i] = i;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (i < j) {
				vc.push_back({ tmp, {i, j} });
			}
		}
	}

	sort(vc.begin(), vc.end());

	int answer = 0;
	for (int i = 0; i < vc.size(); i++) {
		int cost = vc[i].first;
		int nodeA = vc[i].second.first;
		int nodeB = vc[i].second.second;

		// 부모가 같지 않는 경우, 부모 연결
		if (getParent(nodeA) != getParent(nodeB)) {
			answer += cost;
			unionParent(nodeA, nodeB);
		}
	}

	cout << answer << '\n';
}
