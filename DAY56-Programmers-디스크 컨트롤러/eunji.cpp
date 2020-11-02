#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int num = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>> pq;
    int time = jobs[0][0];
    pq.push({ -jobs[0][1],jobs[0][0] });
    jobs.erase(jobs.begin());

    while (!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        time += -(tmp.first);
        answer += time-(tmp.second);

        while (!jobs.empty()&&jobs[0][0] <= time) {
            pq.push({ -jobs[0][1],jobs[0][0] });
            jobs.erase(jobs.begin());
        }
        if (!jobs.empty() && pq.empty()) {
                time = jobs[0][0];
                while (!jobs.empty() && jobs[0][0] <= time) {
                    pq.push({ -jobs[0][1],jobs[0][0] });
                    jobs.erase(jobs.begin());
                }
            }

    }
    return answer/num;
}
