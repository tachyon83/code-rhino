#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> jobsQueue(jobs.begin(), jobs.end()); // {{requesttime, runtime}...}

    while (!jobsQueue.empty())
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> candidates; // {{runtime, requesttime}...}

        do
        {
            auto jcur = jobsQueue.top();
            jobsQueue.pop();
                
            candidates.push({ jcur[1], jcur[0] });
        } while (!jobsQueue.empty() && jobsQueue.top()[0] <= time);

        auto cur = candidates.top();
        candidates.pop();

        int waitingTime = 0;
        if (time > cur[1])
        {
            waitingTime = time - cur[1];
            time += cur[0];
        }
        else
        {
            time = cur[1] + cur[0];
        }
        answer += cur[0] + waitingTime;

        while (!candidates.empty())
        {
            jobsQueue.push({ candidates.top()[1], candidates.top()[0] });
            candidates.pop();
        }
    }

    answer /= jobs.size();

    return answer;
}
