#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> data;
    vector<string> input;
    vector<string> id;
    for(int i = 0; i < record.size(); i++){
        string tmp;
        stringstream sp(record[i]);
        sp >> tmp;
        if(tmp == "Enter"){
            string userId, name;
            sp >> userId >> name;
            input.push_back(tmp);
            id.push_back(userId);
            data[userId] = name;
        }else if(tmp == "Leave"){
            string userId;
            sp >> userId;
            input.push_back(tmp);
            id.push_back(userId);
        }else if(tmp == "Change"){
            string userId, name;
            sp >> userId >> name;
            data[userId] = name;
        }
    }
    
    for(int i = 0; i < id.size(); i++){
        string tmp;
        tmp = data[id[i]] + "님이 ";
        if(input[i] == "Enter"){
            tmp += "들어왔습니다.";
        }else if(input[i] == "Leave"){
            tmp += "나갔습니다.";
        }
        answer.push_back(tmp);
    }
    
    return answer;
}
