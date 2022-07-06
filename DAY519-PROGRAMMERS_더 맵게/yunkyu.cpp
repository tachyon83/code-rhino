#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto s : scoville) {
        pq.push(s);
    }
    
    bool flag = false;
    
    while(!pq.empty()){
        int first = pq.top();
        if(first >= K) { // 현재 가장 낮은 음식의 스코빌 지수가 K 이상이면
            flag = true;
            break;
        }
        pq.pop();
        if(pq.size() == 0) break;
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second); // 첫번째 음식과 두번째 음식을 섞는다
        
        answer++;
    }
    
    if(!flag) answer = -1; // 모든 음식의 스코빌 지수를 K 이상으로 만들수 없을때
    return answer;
}
