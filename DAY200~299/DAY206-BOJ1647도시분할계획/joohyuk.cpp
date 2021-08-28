#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mp make_pair
using namespace std;

const int sz=1e5+1;
int a,b,c,n,m,root[sz],mx,t;
vector<pair<int,pair<int,int> > >v;

int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    root[a]=b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;++i)root[i]=i;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        v.push_back(mp(c,mp(a,b)));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;++i){
        if(find(v[i].second.first)!=find(v[i].second.second)){
            t+=v[i].first;
            merge(v[i].second.first,v[i].second.second);
            mx=max(mx,v[i].first);
        }
    }
    cout<<t-mx;
    return 0;
}
