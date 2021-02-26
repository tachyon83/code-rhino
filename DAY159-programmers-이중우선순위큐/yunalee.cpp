#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(int i = 0; i < operations.size(); i++){
        istringstream iss(operations[i]);
        string input, numStr;
        iss >> input >> numStr;
        
        if(input == "I"){
            dq.push_back(stoi(numStr));
        }else if(input == "D" && !dq.empty()){
            sort(dq.begin(), dq.end());
            if(numStr == "1"){
                dq.pop_back();
            }else if(numStr == "-1"){
                dq.pop_front();
            }
        }
    }
    sort(dq.begin(), dq.end());
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}
