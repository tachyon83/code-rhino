//수정중
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
string solution(int n, int t, int m, vector<string> timetable);
bool canBoard(int last, int n, int t, int m, vector<int> arr);

int main() {
    cout << solution(2, 10, 2, {"09:10", "09:09", "08:00"});


}
string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> arr(timetable.size());
    for (int i = 0; i < timetable.size(); i++) {
        arr[i] = (atoi(&timetable[i][0])) * 60 + (atoi(&timetable[i][3]));
    }
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = 1439;
    int mid = -1;
    while (mid!=end || start!=end) {
        mid = (start + end) / 2+1;
        if (canBoard(mid,n,t,m,arr)) start = mid;
        else end = mid - 1;
    }
    int hour = mid / 60;
    int min = mid % 60;
    string s;
    if (hour < 10) s += "0";
    s += to_string(hour) + ":";
    if (min < 10)s += "0";
    s += to_string(min);
    return s;
}
bool canBoard(int last,int n,int t, int m, vector<int> arr) {
    int point = 0;
    int i = 540;
    if (last > i + (n - 1) * t) return false;
    for (int k = 0; k < n; k++,i+=t) {
        for (int j = 0; j < m; j++) {
            if (point<arr.size() && arr[point] <= i&&arr[point]<=last) point++;
            else if (point>=arr.size() || arr[point] > last) return true;
            else break;
        }
    }
    return false;
}
