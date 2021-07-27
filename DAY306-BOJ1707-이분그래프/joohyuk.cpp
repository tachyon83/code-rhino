#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int sz=2e4+1;
bool flag;
int c[sz],t,v,e,a,b;
vector<int> g[sz];
queue<int>q;

void solve(int i){
    if(c[i]==-1)c[i]=0;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(int nx:g[curr]){
            if(nx==curr)continue;
            if(c[nx]==-1){
                c[nx]=(c[curr]+1)%2;
                q.push(nx);
            }else{
                if(c[nx]!=(c[curr]+1)%2){
                    flag=1;
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t;
    while(t--){
        cin>>v>>e;
        flag=0;
        fill(c,c+v+1,-1);
        for(int i=1;i<=v;++i)g[i].clear();
        while(!q.empty())q.pop();
        while(e--){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=1;i<=v;++i)solve(i);
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
