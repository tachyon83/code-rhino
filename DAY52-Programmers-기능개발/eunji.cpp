#include <string>
#include <vector>
#include <stack>
#include<math.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int>days;
	for (int i = 0; i < speeds.size(); i++) {
		days.push_back(ceil(((float)(100 - progresses[i])) / speeds[i]));
	}
	if (speeds.size() == 1) {
		answer.push_back(1);
	}
	else {
		stack<int> s;
		s.push(days[0]);
		int num = 1;
		for (int i = 1; i < days.size(); i++) {
			if (s.top() < days[i]) {
				s.pop();
				s.push(days[i]);
				answer.push_back(num);
				num = 1;
			}
			else {
				num++;
			}
		}
		answer.push_back(num);

	}
	return answer;
}
