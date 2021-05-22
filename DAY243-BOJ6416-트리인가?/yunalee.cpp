#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<int, int> m;
	set<int> s;
	int tc = 1;

	while (1) {
		int u, v;
		cin >> u >> v;

		//
		if (u == -1 && v == -1) {
			break;
		}

		if (u == 0 && v == 0) {
			bool chk = false;
			int cnt = 0;

			// s의 크기만큼 반복하면서 m에 없는 값이 있는 경우 찾기
			// m에 들어있지 않은 s는 루트를 나타낸다
			// 루트가 존재하므로 chk(트리인지 체크)를 true로 바꾸기
			// 루트의 갯수를 확인하기 위해 cnt를 통해서 갯수를 카운팅해준다
			for (auto iter : s) {
				if (m.find(iter) == m.end()) {
					chk = true;
					cnt++;
				}
			}

			// m의 크기만큼 value(갖고있는 부모노드의 수)가 1개 초과인 경우 찾기
			// value가 1개 초과라면 chk(트리인지 체크)를 false로 바꾼다
			for (auto iter : m) {
				if (iter.second > 1) {
					chk = false;
				}
			}

			// 노드가 1개 이상이면서 루트가 2개 이상 이거나 chk가 false인 경우는 tree가 아닌경우
			// 노드가 0개 이거나 1개 이상일때 루트는 1개이면서 chk도 true라면 tree이다
			if (s.size() > 0 && (cnt > 1 || !chk)) {
				cout << "Case " << tc << " is not a tree.\n";
			}
			else {
				cout << "Case " << tc << " is a tree.\n";
			}
			tc++;
			m.clear();
			s.clear();

			continue;
		}

		if (m.find(v) == m.end()) {
			m.insert({ v, 1 });
		}
		else {
			m[v]++;
		}

		s.insert(v);
		s.insert(u);
	}
}
