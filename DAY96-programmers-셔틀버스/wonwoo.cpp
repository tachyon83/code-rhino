#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int calculateTime(string time) {
	string hour = time.substr(0, 2);
	string minute = time.substr(3, 2);

	return stoi(hour) * 60 + stoi(minute);
}
string solution(int n, int t, int m, vector<string> timetable) {
	vector<int> arriveTime;
	int size = timetable.size();

	for (int i = 0; i < size; i++) {
		arriveTime.push_back(calculateTime(timetable[i]));
	}

	sort(arriveTime.begin(), arriveTime.end());

	int stand = 540;
	int idx = 0;
	int res = 0;

	for (int i = 0; i < n; i++) {
		int full = m;
		for (int j = idx; j < size; j++) {
			if (arriveTime[j] <= stand) {
				idx++;
				full--;
				if (full == 0) {
					break;
				}
			}
		}

		if (i + 1 == n) {
			res = full == 0 ? arriveTime[idx - 1] - 1 : stand;
		}

		stand += t;
		if (stand >= (60 * 24)) {
			break;
		}
	}

	int hours = res / 60;
	string hrs = hours >= 10 ? to_string(hours) : "0" + to_string(hours);

	int minutes = res % 60;
	string mins = minutes >= 10 ? to_string(minutes) : "0" + to_string(minutes);

	return hrs + ":" + mins;
}