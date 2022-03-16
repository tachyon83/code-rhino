#include <iostream>
#include <vector>
#define MAX(x,y) ( (x)>(y)?(x):(y) )
#define ABS(x) ( ((x)<0)?-(x):(x) )
int re(int i);
using namespace std;
int answer = 0;
vector<int> arr(2, 0);
int num;

int main() {
	int height;
	cin >> height;
	num = 1 << (height + 1);
	for (int i = 2; i < num; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	re(1);
	cout << answer;
}

int re(int i) {
	//리프노드면 그대로더하기
	if (i * 2 >= num) {
		answer += arr[i];
		return arr[i];
	}
	else {
		//큰쪽수로 바꾸고 더하기
		int left = re(i * 2);
		int right = re(i * 2 + 1);

		answer = answer + arr[i] + ABS(left - right);
		return (arr[i] + MAX(left, right));
	}
}
