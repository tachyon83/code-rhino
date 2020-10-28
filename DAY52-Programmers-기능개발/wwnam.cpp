#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    const int FINISH = 100;
    int nProgresses = progresses.size();
    vector<int> answer;
    vector<int> cost(nProgresses);

    for (int i = 0; i < nProgresses; i++) {
        cost[i] = ceil(float(FINISH - progresses[i]) / speeds[i]);
    }

    int cur = cost[0];
    answer.push_back(0);
    for (int i = 0; i < nProgresses; i++) {
        if (cost[i] <= cur) {
            answer.back()++;
        }
        else {
            answer.push_back(1);
            cur = cost[i];
        }
    }

    return answer;
}