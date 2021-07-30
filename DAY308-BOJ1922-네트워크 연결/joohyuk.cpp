#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define endl '\n'
using namespace std;

const int sz=1e3+1;
int root[sz],n,m,a,b,c,t;
vector<pair<int,pii> >v;

int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    a=find(a),b=find(b);
    root[a]=b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i)root[i]=i;
    while(m--){
        cin>>a>>b>>c;
        v.push_back(mp(c,mp(a,b)));
    }
    sort(v.begin(),v.end());
    for(auto curr:v){
        c=curr.first,a=curr.second.first,b=curr.second.second;
        if(find(a)!=find(b)){
            merge(a,b);
            t+=c;
        }
    }
    cout<<t;
    return 0;
}
