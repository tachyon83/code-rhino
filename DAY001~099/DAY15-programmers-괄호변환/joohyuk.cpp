#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

bool isCorrect(string p){
    if(!p.size())return 1;
    stack<char> st;
    for(int i=0;i<p.size();++i){
        auto curr=p.at(i);
        if(st.empty()){
            if(curr=='(')st.push(curr);
            else return 0;
        }
        else{
            if(curr=='(')st.push(curr);
            else st.pop();
        }
    }
    if(!st.empty())return 0;
    return 1;
}
bool isBalanced(string p){
    int lp=0,rp=0;
    for(int i=0;i<p.size();++i){
        if(p.at(i)=='(')lp++;
        else rp++;
    }
    if(lp==rp)return 1;
    else return 0;
}
string inverter(string p){
    p=p.substr(1,p.size()-2);
    for(int i=0;i<p.size();++i){
        char& temp=p.at(i);
        if(temp=='(')temp=')';
        else temp='(';
    }
    return p;
}

string solution(string p) {
    if(isCorrect(p))return p;
    int i=1;
    for(;i<p.size();++i){
        if(isBalanced(p.substr(0,i)))break;
    }
    string u=p.substr(0,i);
    string v=p.substr(i);
    if(isCorrect(u))return u+solution(v);
    else{
        string answer="("+solution(v)+")";
        answer+=inverter(u);
        return answer;
    }
}
