#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
using namespace std;
int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    const int NUM_GEAR = 4;
    deque<int> dq[NUM_GEAR + 1];
    for (int i = 1; i <= NUM_GEAR; i++) {
        string s;
        cin >> s;

        int len = s.length();
        for (int j = 0; j < len; j++) {
            dq[i].push_back(s[j] - '0');
        }
    }
       
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, dir, idx, tempDir;
        cin >> num >> dir;
        idx = num;
        tempDir = dir;

        queue<pair<int, int> > q;
        q.push({ idx, tempDir });
        while (idx < NUM_GEAR) {
            idx++;
            tempDir *= -1;
            if (dq[idx - 1][2] != dq[idx][6]) {
                q.push({ idx, tempDir });
            }
            else {
                break;
            }
        }

        idx = num;
        tempDir = dir;
        while (idx > 1) {
            idx--;
            tempDir *= -1;
            if (dq[idx + 1][6] != dq[idx][2]) {
                q.push({ idx, tempDir });
            }
            else {
                break;
            }
        }

        while (!q.empty()) {
            int cur = q.front().first;
            int rotate = q.front().second;
            q.pop();

            if (rotate == 1) {
                int temp = dq[cur].back();
                dq[cur].pop_back();
                dq[cur].push_front(temp);
            }
            else {
                int temp = dq[cur].front();
                dq[cur].pop_front();
                dq[cur].push_back(temp);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= NUM_GEAR; i++) {
        if (dq[i].front() == 1) {
            ans += (int)pow(2, i - 1);
        }
    }

    cout << ans << "\n";
}