class Solution {
private:
    const int INF = 987654321;
    int graph[100][100];

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int res = 0;
        init(n);
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            graph[u][v] =  graph[v][u] = cost;
        }
        
        floyd(n);
        
        int minN = 101;
        for(int i = n - 1; i >= 0; i--){
            int neighbor = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(graph[i][j] <= distanceThreshold){
                    neighbor++;
                }
            }
            if(neighbor < minN){
                res = i;
                minN = neighbor;
            }
        }
        
        return res;
    }
    void init(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                graph[i][j] = INF;
            }
        }
    }
    void floyd(int n){
        int i ,j ,k;
        for(k=0; k<n; k++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(graph[i][k] + graph[k][j] < graph[i][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
};
