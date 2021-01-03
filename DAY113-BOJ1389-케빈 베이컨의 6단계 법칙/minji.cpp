#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, m;
int graph[101][101];

void floydwarshall(void)
{
    
    for(int k = 1; k <= n; k++) 
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if (i==j) 
                    continue;
                else if(graph[i][k] && graph[k][j])
                {
                    if (graph[i][j] == 0)
                        graph[i][j] = graph[i][k] + graph[k][j];
                    else
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    
                }
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        graph[a][b] = graph[b][a] = 1;
    }
    floydwarshall();
    
    int res = INF;
    int person;
    for (int i= 1; i<=n; i++){
        int sum = 0;
        for (int j = 1; j<=n; j++)
            sum += graph[i][j];
        if (res > sum)
        {
            res = sum;
            person = i;
        }
    }
    cout << person << endl;

    return 0;
}
