#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    bool visit[200] = { false, };
    queue<int> q;
    int answer = 0;

    for (int j = 0; j < n; j++) {
        if (visit[j] == true) continue;
        visit[j] = true;
        q.push(j);
        answer++;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (computers[tmp][i] == 1 && visit[i] == false) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    return answer;
}
