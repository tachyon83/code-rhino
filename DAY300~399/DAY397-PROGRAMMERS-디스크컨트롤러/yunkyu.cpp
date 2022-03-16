#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare { // 우선순위 큐 소요시간 오름차순 정렬
    bool operator()(vector<int> a ,vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end()); // 요청시간 오름차순 정렬
    priority_queue<vector<int>,vector<vector<int>>, compare> pq;
    
    int n = jobs.size();
    int time = 0;
    int cnt = 0;
    while(cnt < n || !pq.empty()) {
        if(cnt < n && jobs[cnt][0] <= time) { // 작업이 남았고 현재 시간전까지 요청한 작업이 있다면
            pq.push(jobs[cnt++]);
            continue;
        }
        
        if(!pq.empty()) { // 누적시간과 작업의 실소요시간(누적시간 - 작업 요청시간)을 구함
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else { // 현재까지 요청된 작업이 없다면 다음 작업이 요청되는 시간으로 변경
            time = jobs[cnt][0];
        }
    }
    
    return answer / n;
}
