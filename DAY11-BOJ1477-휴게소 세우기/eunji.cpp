#include <iostream>
#include <vector>
#include <algorithm>
//이분탐색으로 풀어본다.
//사이 거리중 최대값을 m이라 하면, m의 최소값은 고속도로거리/가로등 갯수 m의 최대값은 입력값 가로등 사이거리 중 최대-(추가가로등갯수(소숫점없는 정수라고 생가했을때!)
//이분탐색으로 m의 값을 조율해보면서 검사한다.(m으로 계산햇을때 가로등갯수가 많이 필요하면 m의 값을 늘린다)-->너무 탐색시간이 많이 걸리나? 싶기두 함..
using namespace std;
int curNum, addNum, total;
vector <int>cur;
int count(int dis);

int main() {
	int max=0;
	int mid;
	int x;
	cin >> curNum >> addNum >> total;

	for (int i = 0; i < curNum; i++) {
		cin >> x;
		cur.push_back(x);
		max = x > max ? x : max;
	}
	int start = total / (curNum + addNum);
	int end = max;
	sort(cur.begin(), cur.end());

	while (start<=end) {
		mid = (start + end) / 2;
		int x = count(mid);
		if (x == addNum) {
			while (count(--mid)==addNum) {
			}
			++mid;
			break;
		}
		else if (x > addNum) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	cout << mid;
}

int count(int dis) {
	int sum = 0;
	for (int i = 0; i < curNum-1; i++) {
		int d = cur[i + 1] - cur[i];
		if (d > dis) {
			sum += d / dis;
		}
	}
	return sum;
}
