//모든 간선을 지나게해야된다 => 오일러 경로(한붓그리기)
//오일로 경로는 모든꼭지점이 짝수이거나 단 두개만이 홀수일때 가능하다
//이것을 이용해서 쉽게 구현할수 있지 않을까??
#include <iostream>
#include <vector>
using namespace std;
vector<int> group;
void merge(int v1, int v2);
int find(int v);
int main() {
	int V, E;
	cin >> V >> E;
	vector<int> node(V + 1, 0);
	group.push_back(0);
	for (int i = 1; i <= V; i++) {
		group.push_back(i);
	}

	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		node[v1]++;
		node[v2]++;
		merge(v1, v2);
	}

	//홀수 갯수세기
	int odd = 0;
	for (int i = 1; i <= V; i++) {
		if (node[i] % 2 == 1) {
			odd++;
		}
	}

	//모두 같은 그룹인지 세기
	bool isgroup = true;
	int stand = find(1);
	for (int i = 2; i <= V; i++) {
		if (stand != find(i)) {
			isgroup = false;
			break;
		}
	}

	//모두 홀수이거나 두개만이 홀수일때 가능, 같은 그룹이어야 가능
	if ((odd == 2 || odd == 0) && isgroup) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

void merge(int v1, int v2) {
	int p1 = find(v1);
	int p2 = find(v2);
	if (p1 != p2)
		if (p1 < p2) {
			group[v2] = p1;
		}
		else {
			group[v1] = p2;
		}
}

int find(int v) {
	if (group[v] == v) return v;
	else {
		return find(group[v]);
	}

}
