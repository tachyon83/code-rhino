#include <iostream>
#include <stack>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=1e3+1;
int root[sz],t,n,m,a,b,cnt;
stack<pii> routes;

int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n>>m;
        cnt=0;
        for(int i=1;i<=n;++i)root[i]=i;
        while(m--){
            cin>>a>>b;
            routes.push(mp(a,b));
        }
        while(!routes.empty()){
            auto cp=routes.top();routes.pop();
            a=find(cp.first);b=find(cp.second);
            if(a!=b){
                root[a]=b;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
