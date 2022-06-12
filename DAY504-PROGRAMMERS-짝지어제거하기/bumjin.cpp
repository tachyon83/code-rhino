#include <iostream>
#include<string>
#include<vector>
using namespace std;

int Stack_func(int ans,string s){
    char stack_top='z';
    vector<char> stack;
    stack.push_back(s[0]);
    for(int i=1;i<s.length();i++){
        //stack의 위부분 조회
        //문자열 조회
        //문자열 비교
        if(stack.back()==s[i]){//같음?1-1
        //1-1:stack에서 pop시킴
            stack.pop_back();     
        }
        else{//다름?1-2
            stack.push_back(s[i]);
        //1-2:stack에다 push시킴
        }
    }
    if(stack.size()>0){
        return 0;
    }
    else{
        return 1;   
    }
}

int solution(string s)
{
   
    int answer = -1;
    answer=Stack_func(answer,s);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    return answer;
}
