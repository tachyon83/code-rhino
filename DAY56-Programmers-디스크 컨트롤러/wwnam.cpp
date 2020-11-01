#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}
int solution(vector<vector<int>> jobs) {
    int jobSize = jobs.size();
    vector<pair<int, int> > jobArr(jobSize);
    for (int i = 0; i < jobSize; i++)
        jobArr[i] = make_pair(jobs[i][0], jobs[i][1]);

    sort(jobArr.begin(), jobArr.end(), compare);

    int start = 0, sum = 0;
    while (!jobArr.empty()) {
        jobSize = jobArr.size();
        for (int i = 0; i < jobSize; i++) {
            if (jobArr[i].first <= start) {
                start += jobArr[i].second;
                sum += start - jobArr[i].first;
                jobArr.erase(jobArr.begin() + i);
                break;
            }
            if (i == jobSize - 1)
                start++;
        }
    }

    jobSize = jobs.size();
    return sum / jobSize;
}