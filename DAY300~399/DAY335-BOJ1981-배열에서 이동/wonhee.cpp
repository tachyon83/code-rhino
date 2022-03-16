#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int arr[102][102];
bool visit[102][102];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int min_val = 1000, max_val = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            min_val = min(min_val, arr[i][j]);
            max_val = max(max_val, arr[i][j]);
        }

    int start = 0, end = 200, result = 1000;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        bool startFlag = 0, endFlag = 0;
        for (int i = min_val; i <= max_val-mid; i++)
        {
            startFlag = true;
            if (endFlag)
                break;

            if (arr[0][0] < i || arr[0][0] > i + mid)
                continue;
            memset(visit, 0, sizeof(visit));
            queue<pair<int,int>> q;
            q.push({ 0,0 });
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (visit[y][x])
                    continue;

                visit[y][x] = true;
                for (int j = 0; j < 4; j++)
                {
                    int ny = d[j][0] + y;
                    int nx = d[j][1] + x;

                    if ((0 <= ny && ny < N) && (0 <= nx && nx < N) && !visit[ny][nx] && i <= arr[ny][nx] && arr[ny][nx] <= i + mid)
                    {
                        q.push({ ny,nx });
                        if (ny == N - 1 && nx == N - 1)
                            endFlag = true;
                    }
                }
            }
        }

        if (!startFlag || endFlag)
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << result << '\n';
    return 0;
}