#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int get(int n, int cnt) {
	int res = 0;

	while (cnt > 0) {
		cnt -= 1;
		res += N * pow(10, cnt);
	}

	return res;
}

int solution(int N, int number) {
	int answer = -1;

	const int MIN = 8;

	vector<set<int>> s(MIN);

	int idx = 1;

	for (int i=0; i< s.size(); i++){
		s[i].insert(get_basic_number(N, idx));
		idx += 1;
	}

	for (int i = 1; i < MIN; i++) {
		for (int j = 0; j < i; j++) {
			for (const auto & op1 : s[j]) {
				for (const auto & op2 : s[i - j - 1]) {
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);

					if (op2 != 0)
						s[i].insert(op1 / op2);
				}
			}
		}
		if (s[i].find(number) != s[i].end()) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

int main() {
	int N, number, result;

	result = solution(5, 12);
	cout << result;
}
