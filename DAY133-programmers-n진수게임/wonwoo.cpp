#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string formatter(int number, int jin) {
    string str = "";
    while (number >= jin) {
        int tmp = number % jin;
        if (tmp >= 10) {
            str += tmp % 10 + 'A';
        }
        else {
            str += tmp + '0';
        }
        number /= jin;
    }

    if (number >= 10) {
        str += number % 10 + 'A';
    }
    else if (number) {
        str += number + '0';
    }

    reverse(str.begin(), str.end());
    return str;
}
string solution(int n, int t, int m, int p) {
    string str = "0";
    int turn = m * (t + 1);
    int idx = 1;
    while (str.length() <= turn) {
        str += formatter(idx, n);
        idx++;
    }

    string answer = "";
    for (int i = 0; i < t; i++) {
        answer += str[i * m + p - 1];
    }

    return answer;
}