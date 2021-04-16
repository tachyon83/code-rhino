#include <iostream>
#define endl '\n'
using namespace std;
const int INF=100;
int dist[101][101];
int n,m,a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<n+1;++i) fill(dist[i],dist[i]+n+1,INF);
    while(m--){
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }

    for(int k=1;k<n+1;++k){
        for(int i=1;i<n+1;++i){
            for(int j=1;j<n+1;++j){
                if(i==j){
                    dist[i][j]=0;
                    continue;
                }
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    
    int p,mn=(n-1)*(n-1)+1;
    for(int i=1;i<n+1;++i){
        int s=0;
        for(int j=1;j<n+1;++j){
            s+=dist[i][j];
        }
        if(mn>s){
            mn=s;
            p=i;
        }
    }
    cout<<p<<endl;
    return 0;
}
