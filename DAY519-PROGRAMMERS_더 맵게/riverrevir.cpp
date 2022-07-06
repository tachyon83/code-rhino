#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int e: scoville) pq.push(e);
    
    while(pq.top() < K) {
        // 스코빌 지수를 K 이상으로 만들 수 없는 경우 -1 리턴
        if(pq.size()==1) return -1;
            
        // 제일 작은 값
        int tmp1 = pq.top();  
        pq.pop();
        
        // 그다음 작은 값
        int tmp2 = pq.top();  
        pq.pop();
        
        // 섞은 값 넣기
        int new_scoville = tmp1 + (tmp2*2);
        pq.push(new_scoville);
        
        answer++;
    }
    
    return answer;
}
