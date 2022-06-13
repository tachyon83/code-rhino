#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(string s) {
    vector<int> v;
    v.push_back(s[0]);
    
    // 스택 자료구조 활용
    for(int i = 1; i < s.length(); i++){
        int top = v[v.size() - 1];
        if(top == s[i]) { // top이 현재 문자와 같다면 pop
            v.pop_back();
        }
        else { // top이 현재 문자와 다르다면 push
            v.push_back(s[i]);
        }
    }
    
    // 스택이 모두 비었는지
    return v.size() == 0;
}

int solution(string s)
{
    int answer = solve(s);

    return answer;
}
