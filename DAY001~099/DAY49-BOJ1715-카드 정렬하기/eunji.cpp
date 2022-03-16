//첨엔 우선순위 큐인지 모르고 삽질을 계속햇어여...
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int> card;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		card.push(-x);
	}
	int sum = 0;
	while (card.size()>1) {
		int c1 = card.top();
		card.pop();
		int c2 = card.top();
		card.pop();
		int tmp = c1 + c2;
		sum += tmp;
		card.push(tmp);
	}
	cout << -sum;

}
