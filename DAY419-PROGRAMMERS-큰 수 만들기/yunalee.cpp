#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length() - k;
    
    int maxIdx = -1;
    int start = maxIdx;
    while (len) {
        int max = 0;
        for (int i = number.length() - len; i > start; i--) {
            if (max <= number[i] - '0') {
                max = number[i] - '0';
                maxIdx = i;
            }
        }

        start = maxIdx;
        answer += (max + '0');
        len--;
    }

    return answer;
}
