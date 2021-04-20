#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=1e5+1;
int pts[sz],n,m,a,b;
vector<int> sub[sz];

void handover(int curr,int passdown){
    for(int nx:sub[curr]){
        pts[nx]+=passdown;
        handover(nx,pts[nx]);
    }
}

void process(){
    int node=1;
    handover(node,pts[node]);
}

void printer(){
    for(int i=1;i<=n;++i)cout<<pts[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a;
        if(a==-1)continue;
        sub[a].push_back(i+1);
    }
    while(m--){
        cin>>a>>b;
        pts[a]+=b;
    }
    process();
    printer();
    return 0;
}
