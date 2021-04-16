#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        q.push(i);
        answer++;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (computers[cur][j] && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    return answer;
}