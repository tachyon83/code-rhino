#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int sz=3e3+1;
vector<int>graph[sz];
int v,E,a,b;
bool flag,routes[sz][sz];

void solve(int a,int cnt){
    if(cnt==E){
        flag=1;
        return;
    }
    for(int e:graph[a]){
        if(!routes[a][e]){
            routes[a][e]=1;
            routes[e][a]=1;
            solve(e,cnt+1);
            if(flag)return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>v>>E;
    for(int i=0;i<E;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=v;++i){
        for(int j=1;j<=v;++j)fill(routes[j],routes[j]+v+1,0);
        solve(i,0);
        if(flag){
            cout<<"YES";
            break;
        }

    }
    if(!flag)cout<<"NO";
    return 0;
}
