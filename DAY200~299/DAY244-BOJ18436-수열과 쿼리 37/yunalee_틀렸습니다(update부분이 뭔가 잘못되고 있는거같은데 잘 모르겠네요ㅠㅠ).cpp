#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> vc;
vector<int> tree;

int init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = vc[start];
	}
	
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || index > end) {
		return;
	}
	
	tree[node] += dif;
	
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;
	
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int solution(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return solution(start, mid, node * 2, left, right) + solution(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vc.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> K;
		vc[i] = K % 2;
	}

	tree.resize(4 * (N + 1));

	init(1, N, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			/*
			* 바뀔 숫자의 홀수/짝수인 경우가 기존과 같다면 update 진행을 하지 않고
			* 다른 경우만 진행
			* 홀수로 변경되는 경우, +1
			* 짝수로 변경되는 경우, -1
			* 이렇게 생각해서 udpate를 만들었는데.. 주어진 테스트케이스 말고 계속 틀리는거 보면
			* update가 잘 안되는거 같네요ㅠㅠ
			*/
			if (vc[b] != c % 2) {
				c = c % 2 == 1 ? 1 : -1;
				update(1, N, 1, b, c);
			}
		}
		else if (a == 2) {
			int result = solution(1, N, 1, b, c);
			cout << c - b + 1 - result << '\n';
		}
		else if (a == 3) {
			int result = solution(1, N, 1, b, c);
			cout << result << '\n';
		}
	}
}
