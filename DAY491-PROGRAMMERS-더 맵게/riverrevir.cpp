#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> s, int K) {
    int answer = 0;
    
    priority_queue <int,vector<int>,greater<int>> pq(s.begin(),s.end());
    
    while(pq.size()>1 && pq.top()<K) {
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        int three = one+two*2;
        pq.push(three);
        answer++;
    }
    if(pq.top()<K) return -1;
    else return answer;
}
