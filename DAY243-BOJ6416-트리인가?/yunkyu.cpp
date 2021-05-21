#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	int a, b;
	int edge = 0;

	while (1) {
		cin >> a >> b;
		if (a < 0 && b < 0) // 종료
			break;
		if (a == 0 && b == 0) {
			if (edge == 0 || edge == st.size() - 1) { // 노드가 0 개이거나 엣지가 노드-1개 면 트리
				printf("Case %d is a tree.\n", t);
			}
			else {
				printf("Case %d is not a tree.\n", t);
			}
			t++;
			st.clear();
			edge = 0;
		}
		else {
			//set에 노드 저장
			st.insert(a); 
			st.insert(b);
			edge++;
		}
	}
	return 0;
}
