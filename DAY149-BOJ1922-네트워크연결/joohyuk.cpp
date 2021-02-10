#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=1000+1;
int n,m,a,b,c,roots[sz],t;
vector<pair<int,pair<int,int> > >v;

int find(int a){
    if(roots[a]==a)return a;
    return roots[a]=find(roots[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    roots[a]=b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i)roots[i]=i;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        v.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(v.begin(),v.end());

    for(auto e:v){
        if(find(e.second.first)!=find(e.second.second)){
            merge(e.second.first,e.second.second);
            t+=e.first;
        }
    }
    cout<<t;
    return 0;
}
