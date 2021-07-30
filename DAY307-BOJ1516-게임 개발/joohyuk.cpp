#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=5e2+1;
vector<int> g[sz];
int n,t[sz],c,pv,ind[sz],tc[sz];
queue<int>q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
        while(1){
            cin>>pv;
            if(pv!=-1){
                g[pv].push_back(i);
                ind[i]++;
            }else break;
        }
    }
    for(int i=1;i<=n;++i)if(!ind[i])q.push(i);
    while(!q.empty()){
        int curr=q.front();q.pop();
        tc[curr]+=t[curr];
        for(int nx:g[curr]){
            tc[nx]=max(tc[nx],tc[curr]);
            ind[nx]--;
            if(!ind[nx])q.push(nx);
        }
    }
    for(int i=1;i<=n;++i)cout<<tc[i]<<endl;
    return 0;
}
