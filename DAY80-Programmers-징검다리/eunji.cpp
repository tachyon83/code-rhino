#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n);
int countD(int mid, vector<int> rocks);
int solution(int distance, vector<int> rocks, int n) {
	rocks.push_back(0);
	rocks.push_back(distance);
	sort(rocks.begin(), rocks.end());
	for (int i = 0; i < rocks.size() - 1; i++) {
		rocks[i] = rocks[i + 1] - rocks[i];
	}
	rocks.pop_back();
	int start = *min_element(rocks.begin(), rocks.end());
	int end = distance;
	int mid = 0;
	while (start < (end - 1)) {
		mid = (start + end) / 2;
		if (countD(mid, rocks) <= n) {
			start = mid;
		}
		else {
			end = mid - 1;
		}
	}
	return end;

}
int countD(int mid, vector<int> rocks) {
	int count = 0;
	for (int i = rocks.size() - 1; i > 0; i--) {
		if (rocks[i] < mid) {
			rocks[i - 1] += rocks[i];
			count++;
			rocks.erase(rocks.begin() + i);
		}
	}
	while (rocks[0] < mid) {
		rocks[0] += rocks[1];
		rocks.erase(rocks.begin() + 1);
		count++;
	}
	return count;
}
