class Solution {
private:
    const int big=1e4+1;
    int dist[101][101];
    
    void init(int n){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j){
                    dist[i][j]=0;
                    continue;
                }
                dist[i][j]=big;
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        init(n);
        for(auto&v:edges){
            dist[v[0]][v[1]]=min(dist[v[0]][v[1]],v[2]);
            dist[v[1]][v[0]]=min(dist[v[1]][v[0]],v[2]);
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    int temp=dist[i][k]+dist[k][j];
                    if(temp>distanceThreshold)continue;
                    if(temp<dist[i][j])dist[i][j]=temp;
                }
            }
        }
        
        int mn=n,cn=0;
        for(int i=0;i<n;++i){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(i==j)continue;
                if(dist[i][j]<=distanceThreshold)cnt++;
            }
            if(cnt<=mn){
                mn=cnt;
                cn=i;
            }
        }
        return cn;
    }
};
