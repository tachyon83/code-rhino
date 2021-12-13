#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> Queue;
    
    for(int i = 0; i < priorities.size(); i++){
        Queue.push(make_pair(priorities[i], i));
    }
    
    while(1){
        int maxVal = *max_element(priorities.begin(), priorities.end());
        int maxIdx = max_element(priorities.begin(), priorities.end()) - priorities.begin();
        if(Queue.front().first < maxVal){
            Queue.push(make_pair(Queue.front().first, Queue.front().second));
            Queue.pop();
        }else{
            if(Queue.front().second == location){
                answer++;
                break;
            }else{
                answer++;
                priorities.erase(priorities.begin()+maxIdx);
                Queue.pop();
            }
        }
    }
    
    return answer;
}
