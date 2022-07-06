#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int start=0;
    while(start<progresses.size()){
        queue<int> q;
        if(progresses[start]>=100){
             for(int i=start; i<progresses.size();i++){
                    q.push(progresses[i]);
             } 
            int count=0;

            while(true){
                if(q.front()>=100&&!q.empty()){
                    count++;
                    q.pop();
                }
                else{
                    start+=count;
                    answer.push_back(count);
                    break;
                }
            }
        }
        else{
                 for(int i=start; i<progresses.size();i++){
                    progresses[i]+=speeds[i];
             }   
        }

    }
    return answer;
}
