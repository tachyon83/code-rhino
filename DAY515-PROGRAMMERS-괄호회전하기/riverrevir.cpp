#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {

    int answer(0);
    int idx(0), idx2(0);
    string copy_s(s);

    for (idx = 0; idx < s.size(); ++idx) {
        stack<char>st;
        for (idx2 = 0; idx2 < s.size(); ++idx2) {
            if (st.empty()) {
                st.push(s[idx2]);
            }
            else {
                if (st.top() == '(' && s[idx2] == ')') {
                    st.pop();
                }
                else if (st.top() == '[' && s[idx2] == ']') {
                    st.pop();
                }
                else if (st.top() == '{' && s[idx2] == '}') {
                    st.pop();
                }
                else st.push(s[idx2]);
            }
        }
        if (st.empty())
            answer++;

        for (idx2 = 0; idx2 + 1 < s.size(); ++idx2) {
            copy_s[idx2] = s[idx2 + 1];
        }
        copy_s[idx2] = s[0];
        s = copy_s;
    }

    return answer;
}
