#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;
    string cur_str = "";
    
    dict.push_back("");
    
    // A ~ Z까지 사전 만들기
    for(char ch = 'A'; ch <= 'Z'; ch++){
        string tmp_str = "";
        tmp_str += ch;
        dict.push_back(tmp_str);
    }
    
    for(int i = 0; i < msg.length(); i++){
        cur_str += msg[i];
        
        // 현재 문자열이 사전에 있음
        if(find(dict.begin(), dict.end(), cur_str) != dict.end()
            && find(dict.begin(), dict.end(), cur_str + msg[i + 1]) == dict.end()){
            answer.push_back(find(dict.begin(), dict.end(), cur_str) - dict.begin());
            dict.push_back(cur_str + msg[i + 1]);
            cur_str = "";
        }
    }
    
    return answer;
}
