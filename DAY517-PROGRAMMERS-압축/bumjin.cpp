#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    unordered_map<string,int> table;
    vector<int> answer;
    //index 26으로 설정
    int index=26;
    //A~Z까지 HASH에 저장
    for(int i=0;i<26;i++){
        string temp;
        temp=char(65+i);
        table.insert({temp,i+1});
    }
    //HASH와 문자열 비교
    int start=0;
    int end=0;
    while(end<=msg.size()-1){
        string check="";
        check=msg.substr(start,end-start+1);
        if(table.find(check)!=table.end()){
            end++;
        }
        else{
            index++;
            table.insert({check,index});
            answer.push_back(table[msg.substr(start,end-start)]);
            start=end;
        }
    } 
    string final=msg.substr(start,end-start+1);
    if(table.find(final)!=table.end()){
        answer.push_back(table[final]);
    }
    else{
        table.insert({final,index});
        answer.push_back(index);
    }
    //printf("%s\n",final.c_str());
    return answer;
}
