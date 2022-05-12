#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map<string,string> m;
vector<string> solution(vector<string> record) {
    vector<string> answer,state;
    for(int i=0;i<record.size();i++){
        string str=record[i];
        stringstream streamStr(str);
        string msg,id,nickname;
        streamStr>>msg>>id>>nickname;
        if(msg=="Enter"){
            state.push_back("님이 들어왔습니다.");
            answer.push_back(id);
            m[id]=nickname;
        }
        else if(msg=="Leave"){
            state.push_back("님이 나갔습니다.");
            answer.push_back(id);
        }
        else{
            m[id]=nickname;
        }
    }
    for(int i=0;i<state.size();i++){
        answer[i]=m[answer[i]]+state[i];
    }
    return answer;
}
