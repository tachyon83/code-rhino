#include <string>
#include <vector>
#include <deque>
#include<algorithm>
using namespace std;
vector<int> solution(vector<string> operations);

vector<int> solution(vector<string> operations) {
    deque<int> dq;
    vector<int> answer(2, 0);
  
    for (int i = 0; i < operations.size(); i++) {
        string s = operations[i];
        if (s[0] == 'I') {
            s.erase(0, 2);
            int num = atoi(s.c_str());
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else {
            if (dq.empty()) continue;
            if (s[2] == '1') {
                dq.pop_back();

            }
            else {
                dq.pop_front();
            }

        }
    }
    if (dq.empty()) return answer;
    else {
        answer[0] = dq.back();
        answer[1] = dq.front();
        return answer;
    }
}
