#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int,int>> graph[201];
int route[201][201];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (route[i][j] == 0)
                printf("- ");
            else
                printf("%d ", route[i][j]);
        }
        printf("\n");
    }
}
void dijsktra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);

    pq.push({0,start});
    dist[start] = 0;
    int i,j;

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d > dist[curr]) continue; // 이미 체크한 경로라면 스킵


        for (i = 0; i < graph[curr].size(); i++) {
            int cost = d + graph[curr][i].second;
            int next = graph[curr][i].first;
            if (cost < dist[next]) { // 더 짧은 경로라면 갱신하고 우선순위큐에 경로 삽입
                if (curr == start) { // 가장 먼저 거쳐야 하는 집하장을 구하기 위해 시작 집하장을 따로 처리
                    route[start][next] = next;
                }
                else {
                    route[start][next] = route[start][curr]; // 현재 경로에 가장 먼저 거친 집하장을 앞에서 불러온다
                }
                dist[next] = cost;
                pq.push({ cost,next });
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    int i;

    for (i = 0; i < m; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        // 양방향 그래프 연결
        graph[from].push_back({ to,cost });
        graph[to].push_back({ from,cost });
    }

    for (i = 1; i <= n; i++) // 각 집하장에 대하여 최단경로와 경로표 구함
        dijsktra(i);

    print(); // 경로표 출력
    return 0;
 }
