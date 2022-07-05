#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> scoville, int K) {
    priority_queue<int> pq;
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    int leastspicy;
    int second_spicy;
    int mixed;
    int cord=-pq.top();
     while(cord<K){
        if(pq.size()==1&&pq.top()<K){
            answer=-1;
            return answer;
        }
        leastspicy=pq.top(); 
        pq.pop();
        second_spicy=pq.top();
        pq.pop();
        mixed=(second_spicy*2)+leastspicy;
        pq.push(mixed);  
        answer++;
        cord=-pq.top();  
     }
    
    return answer;
}
