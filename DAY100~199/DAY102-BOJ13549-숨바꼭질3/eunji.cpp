#include <iostream>
#include <queue>
#include <memory>
using namespace std;
int doDFS(int x, int target);
int main() {
	int N, K;
	cin >> N >> K;
	cout << doDFS(N, K);
	return 0;
}
int arr[100001]={0, };
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int doDFS(int x, int target) {

	pq.push({ 0,x });
	arr[x] = 0;
	//queue엔 위치와 시간을 넣는다.
	while (!pq.empty()) {
		int depth = pq.top().first;
		int pos = pq.top().second;
		//찾을시 바로 시간 리턴
		if (pos == target) return depth;
		pq.pop();
		//음수일땐 어떤연산이든 불가.
		if (pos < 0) continue;
		if (pos>0 && arr[pos - 1]==0 ||arr[pos-1] > depth + 1) {
			pq.push({ depth + 1,pos - 1 });
			arr[pos - 1] = depth + 1;
		}
		//만약 동생을 지나쳤다면 더이상 더하거나 곱할필요없음.
		if (pos > target) continue;
		if (arr[pos + 1]==0||arr[pos+1] > depth + 1) {
			pq.push({ depth + 1, pos + 1 });
			arr[pos + 1] = depth + 1;
		}
		if (pos>0&&pos * 2 <= 100000 && (arr[pos*2]==0 ||arr[pos * 2] > depth)) {
			pq.push({ depth, pos * 2 });
			arr[pos * 2] = depth;
		}
	}
	//return arr[x];
}
