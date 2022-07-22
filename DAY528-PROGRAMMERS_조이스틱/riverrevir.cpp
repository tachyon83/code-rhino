#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int turn = n - 1; //조이스틱을 한 방향으로 쭉 움직였을 때
    for (int i = 0; i < n; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;
    return answer;
}
