#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int workCnt = jobs.size();
    vector<pair<int, int>> readyQ;
    sort(jobs.begin(), jobs.end());

    int startTime = 0;
    int endTime = 0;
    while (readyQ.size() > 0 || jobs.size() > 0) {
        if (readyQ.size() == 0) {
            readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));
            jobs.erase(jobs.begin());
        }

        if (endTime >= readyQ[0].first) {
            startTime = endTime;
        }
        else {
            startTime = readyQ[0].first;
        }
        endTime = startTime + readyQ[0].second;
        
        while (jobs.size() > 0 && jobs[0][0] <= endTime) {
            if (endTime >= jobs[0][0]) {
                readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));
                jobs.erase(jobs.begin());
            }
        }

        answer = answer + (endTime - readyQ[0].first);
        readyQ.erase(readyQ.begin());
        sort(readyQ.begin(), readyQ.end(), comp);
    }

    return answer / workCnt;
}
