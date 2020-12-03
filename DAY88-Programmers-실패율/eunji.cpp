#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> solution(int N, vector<int> stages);
bool compare(pair<double, int> a, pair<double, int>b);

vector<int> solution(int N, vector<int> stages) {
	sort(stages.begin(), stages.end());
	vector<pair<double, int>> fail(N);
	int num = 1;
	int i = -1;

	while (num <= N) {
		int count = 0;
		while (num == stages[++i] && i < stages.size()) count++;
		int dojun = (stages.size() - (--i) + count - 1);
		if (dojun != 0) {
			fail[num - 1] = { (double)count / dojun,num };
		}
		else {
			fail[num - 1] = { 0.0,num };
		}
		num++;
	}
	sort(fail.begin(), fail.end(), compare);
	vector <int> answer(N);
	for (int i = 0; i < N; i++) {
		answer[i] = fail[i].second;
	}
	return answer;
}

bool compare(pair<double, int> a, pair<double, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
