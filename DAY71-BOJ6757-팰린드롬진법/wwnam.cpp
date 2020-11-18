/* 통과는 한 풀이 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int X;
vector<int> ans;
bool palindrome() {
	int size = ans.size();
	for (int i = 0; i < size / 2; i++) {
		if (ans[i] != ans[size - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	cin >> X;
	for (int i = 2; i * i <= X; i++) {
		ans.clear();
		int cur = X;
		while (cur) {
			ans.push_back(cur % i);
			cur /= i;
		}
		if (palindrome()) {
			cout << i << '\n';
		}
	}

	for (int i = sqrt(X); i >= 1; i--) {
		if ((X - i) % i == 0 && (X - i) / i > i) {
			cout << (X - i) / i << '\n';
		}
	}
}

/* 시도했지만 79%에서 망한(?) 풀이
   이 풀이 방식은 5(101)과 6(110)을 모두 팰린드롬으로 봅니다.
   오로지 2진법에 라인에 대해서만 이런 문제가 발생해서
   2진법만 따로 처리하면 정답이 나올 것 같습니다.
*/

/*
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool checkDigitLength(int X, int d) {
	int cnt = 0;
	int cur = X;
	while (cur) {
		cur /= d;
		cnt++;
	}
	return (cnt == 2);
}
bool checkBase(int X, int b) {
	vector<int> arr(33, -1);
	int cur = X;
	int top = 0;

	while (cur) {
		arr[top++] = cur % b;
		cur /= b;
	}
	for (int i = 0; i < top / 2; i++) {
		if (arr[i] != arr[top - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	unordered_set<int> candidate;
	int X;
	cin >> X;

	// 3자리 이상 표기해야 하는 진법
	for (int base = 2; !checkDigitLength(X, base); base++) {
		if (checkBase(X, base)) {
			cout << base << '\n';
		}
	}

	// 2자리 표기 가능한 진법
	for (int base = 1; base * base <= X; base++) {
		if (X % base) {
			continue;
		}
		candidate.insert(base);
		candidate.insert(X / base);
	}

	vector<int> candArr(candidate.begin(), candidate.end());
	sort(candArr.begin(), candArr.end());
	int size = candArr.size();
	for (int i = 0; i < size; i++) {
		int zari = X / candArr[i];
		int base = candArr[i];
		if (zari < base) {
			cout << base - 1 << '\n';
		}
	}
}
*/