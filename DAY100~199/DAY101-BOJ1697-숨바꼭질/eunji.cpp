#include <iostream>
#include <queue>
using namespace std;
int doDFS(int x, int target);
int main() {
	int N, K;
	cin >> N >> K;
	cout << doDFS(N, K);
	return 0;
}
bool arr[200001] = { false, };
int doDFS(int x, int target) {

	queue <pair<int, int>> q;

	q.push({ x,0 });
	arr[x] = true;

	//queue엔 위치와 시간을 넣는다.
	while (!q.empty()) {
		int pos = q.front().first;
		int depth = q.front().second;
		//찾을시 바로 시간 리턴
		if (pos == target) return depth;
		q.pop();
		//음수일땐 어떤연산이든 불가.
		if (pos < 0) continue;
		if (arr[pos - 1] == 0) {
			q.push({ pos - 1,depth + 1 });
			arr[pos - 1] = true;
		}
		//만약 동생을 지나쳤다면 더이상 더하거나 곱할필요없음.
		if (pos > target) continue;
		if (arr[pos + 1] == 0) {
			q.push({ pos + 1,depth + 1 });
			arr[pos + 1] = true;
		}
		if (pos * 2 <= 200000 && arr[pos * 2] == 0) {
			q.push({ pos * 2,depth + 1 });
			arr[pos * 2] = true;
		}
	}
}
