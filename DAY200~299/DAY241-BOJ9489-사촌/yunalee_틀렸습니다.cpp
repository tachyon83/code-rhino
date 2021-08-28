#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	while (1) {
		cin >> N >> K;
		if (N == 0 && K == 0) {
			break;
		}

		int arr[1001] = { 0, };
		vector<pair<int, int>> vc;
		int depth = 0;
		int parent = -1;
		int pIdx = 0;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		vc.push_back({ parent, depth });
		int cnt = 0;
		int findParent = parent;
		int findDepth = depth;
		for (int i = 1; i < N; i++) {
			if (arr[i] != arr[i - 1] + 1) {
				parent++;	//지금까지의 집합을 자식으로 갖을수 있는 부모 index구하기
				depth = vc[parent].second + 1;	//부모 깊이 + 1
			}

			vc.push_back({ parent, depth });
			if (arr[i] == K) {
				findParent = parent;
				findDepth = depth;
			}
		}

		int answer = 0;

		for (int i = 0; i < N; i++) {
			//부모가 다르면서 깊이가 같은 사촌 찾기
			if (vc[i].first != findParent && vc[i].second == findDepth) {
				answer++;
			}
		}

		cout << answer << '\n';

	}
}
