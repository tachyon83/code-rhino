#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> rest;
    int len = progresses.size();
    int max = 0;
    for (int i = 0; i < len; i++) {
        int restWork = 100 - progresses[i]; //남은 작업량
        
        //남은 작업량 처리 기간
        int restDay = ceil((double)restWork / speeds[i]);
        rest.push_back(restDay);
    }

    queue<int> Queue;
    Queue.push(rest[0]);
    for (int i = 1; i < len; i++) {
        //기준이 되는 작업보다 이후 기능의 작업이 먼저 끝난 경우 배포할 작업 추가
        if (Queue.front() >= rest[i]) {
            Queue.push(rest[i]);
        }
        else {
            //기준이 되는 작업보다 이후 기능의 작업이 나중에 끝나는 경우
            answer.push_back(Queue.size()); //배포할 작업 갯수
            while (!Queue.empty()) {
                Queue.pop();    //배포한 작업은 pop
            }
            Queue.push(rest[i]);    //현재 작업
        }
    }

    if (!Queue.empty()) {
        answer.push_back(Queue.size());
    }

    return answer;
}
