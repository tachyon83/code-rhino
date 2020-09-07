#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int count = s.size();
	for (int num = 1; num <= (s.size()) / 2; num++) {
		int cc = 0;
		int j;
		int tmpcount = num;
		string tmp = s.substr(0, num);
		for (j = num; j <= s.size() - num; j += num) {
			if (!tmp.compare(s.substr(j, num))) {
				if (cc == 0) {
					cc = 1;
					tmpcount += 1;
				}
			}
			else {
				cc = 0;
				tmp = s.substr(j, num);
				tmpcount += num;
			}
		}
		tmpcount += (s.size() - j);
		if (tmpcount < count) {
			count = tmpcount;
		}
	}
	return count;
}