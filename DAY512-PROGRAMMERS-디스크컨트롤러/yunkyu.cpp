#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(vector<int> a ,vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end()); // 요청 시점 기준 오름차순 정렬
    priority_queue<vector<int>,vector<vector<int>>, compare> pq; // 소요시간 기준 오름차순 정렬
    
    int n = jobs.size();
    int time = 0;
    int cnt = 0;
    while(cnt < n || !pq.empty()) {
        if(cnt < n && jobs[cnt][0] <= time) { // 요청 시점이 소요된 시간 이전일 때
            pq.push(jobs[cnt++]);
            continue;
        }
        
        // 대기하고 있는 작업이 존재할 때
        if(!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0]; // 요청부터 소요된 시간 누적
            pq.pop();
        }
        else { // 다음 작업의 요청시점으로 이동
            time = jobs[cnt][0];
        }
    }
    
    return answer / n;
}
