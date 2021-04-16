#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int head = 0;
    int tail = people.size()-1;
    while(head <= tail){
        if(head == tail){
            answer++;
            break;
        }
        if(people[head] + people[tail] <= limit){
            answer++;
            head++;
            tail--;
        }else{
            answer++;
            tail--;
        }
    }
    
    return answer;
}
