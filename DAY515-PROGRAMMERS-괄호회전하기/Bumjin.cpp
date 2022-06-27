#include <string>
#include <vector>
#include <stack>
using namespace std;

int Check(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(st.empty()){
            return 0;
        }
        else if(st.top()=='('&&s[i]==')'){
            st.pop();
        }
        else if(st.top()=='['&&s[i]==']'){
            st.pop();
        }
        else if(st.top()=='{'&&s[i]=='}'){
            st.pop();
        }
    } 
    if(!st.empty()){
        return 0;
    }
    return 1;
}

int solution(string s) {
    int start=0;
    int end=s.size()-1;
    int fixed=end;
     int answer = 0;
    string extract;
    s=s+s;
    for(int i=0;i<fixed;i++){
        extract=s.substr(start,end+1);
        answer=answer+Check(extract);
        start++;
    }
    
   
    return answer;
}
