#include <string>
#include <stack>
using namespace std;
 
int solution(string s) {
    stack<char> str;
    for (int i = 0; i < s.length(); i++) {
        if (str.empty() || str.top() != s[i])    str.push(s[i]);
        else if (str.top() == s[i])        str.pop();
    }
    if (str.empty())    return 1;
    return 0;
}
