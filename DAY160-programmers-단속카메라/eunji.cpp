#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b);

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int pos = -40000;
	sort(routes.begin(), routes.end(), cmp);
	for (int i = 0; i < routes.size(); i++) {
		if (pos < routes[i][0]) {
			answer++;
			pos = routes[i][1];
		}
	}
	return answer;
}
bool cmp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

