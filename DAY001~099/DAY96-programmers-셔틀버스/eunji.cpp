#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
string solution(int n, int t, int m, vector<string> timetable);
int canBoard(int n, int t, int m, vector<int> arr);

string solution(int n, int t, int m, vector<string> timetable) {
	vector<int> arr(timetable.size());
	for (int i = 0; i < timetable.size(); i++) {
		arr[i] = (atoi(&timetable[i][0])) * 60 + (atoi(&timetable[i][3]));
	}
	sort(arr.begin(), arr.end());
	int min = canBoard(n, t, m, arr);
	int hour = min / 60;
	min = min % 60;
	string s;
	if (hour < 10) s += "0";
	s += to_string(hour) + ":";
	if (min < 10)s += "0";
	s += to_string(min);
	return s;
}
int canBoard(int n, int t, int m, vector<int> arr) {
	int last = 540 + (n - 1) * t;
	int point = 0;
	int num;
	for (int i = 540; i <= last; i += t) {
		num = 0;
		while (num < m) {
			if (point >= arr.size()) return last;
			else if (arr[point] <= i) { num++; point++; }
			else break;
		}
	}
	if (num == m) {
		return arr[--point] - 1;
	}
	else {
		return last;
	}
}
