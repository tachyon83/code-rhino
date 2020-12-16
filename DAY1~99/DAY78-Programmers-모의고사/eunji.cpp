#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
   int first = 0;
	int second = 0;
	int third = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (i % 5 + 1 == answers[i]) {
			first++;
		}

		if (i % 2 == 0) {
			if (answers[i] == 2) {
				second++;
			}
		}
		else {
			switch (i / 2 % 4) {
			case 0:
				if (answers[i] == 1) second++;
				break;
			case 1:
				if (answers[i] == 3)  second++;
				break;
			case 2:
				if (answers[i] == 4)  second++;
				break;
			case 3:
				if (answers[i] == 5) second++;
			}
		}

		switch (i / 2 % 5) {
		case 0:
			if (answers[i] == 3) third++;
			break;
		case 1:
			if (answers[i] == 1) third++;
			break;
		case 2:
			if (answers[i] == 2) third++;
			break;
		case 3:
			if (answers[i] == 4) third++;
			break;
		case 4:
			if (answers[i] == 5) third++;
			break;
		}
	}
	vector<int> answer;
	vector<int> tmp = { first,second,third };
	sort(tmp.begin(), tmp.end());
	if (tmp[2] == first) {
		answer.push_back(1);
	}
	if (tmp[2] == second) {
		answer.push_back(2);
	}
	if (tmp[2] == third) {
		answer.push_back(3);
	}
	return answer;
}
