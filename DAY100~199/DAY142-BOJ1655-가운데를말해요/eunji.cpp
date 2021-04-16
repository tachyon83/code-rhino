#include<iostream>
#include<queue>
using namespace std;
int main() {
	//vector정렬과, 버블소트는 시간초과
	//받은값이 이전출력값보다 크고작을때 나눠서 생각
	//수정중...
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int> arr;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push(num);
		//for (j = i; j > 0; j--) {
		//	if (arr[j - 1] <= num) { arr.insert(arr.begin() + j, num); break; }
		//}
		//if (j == 0) arr.insert(arr.begin(), num);
		cout << arr[i / 2] << "\n";
	}
	return 0;
}
