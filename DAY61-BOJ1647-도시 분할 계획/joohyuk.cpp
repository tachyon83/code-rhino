#include <iostream>
#include <queue>
#define endl '\n'
#define mp make_pair
using namespace std;
const int sz=1e5+1;
priority_queue<pair<int,pair<int,int> > >edges;
int root[sz];
int n,m,a,b,c,mx,cost,p1,p2,w;

int find(int a){
    if(!root[a])return a;
    root[a]=find(root[a]);
    return root[a];
}
void merge(int a,int b){
    a=find(a);b=find(b);
    if(a<b)root[b]=a;
    else root[a]=b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    while(m--){
        cin>>a>>b>>c;
        edges.push(mp(-c,mp(a,b)));
    }
    while(!edges.empty()){
        auto curr=edges.top();edges.pop();
        p1=find(curr.second.first);
        p2=find(curr.second.second);
        w=curr.first*(-1);
        if(p1!=p2){
            cost+=w;
            mx=max(mx,w);
            merge(p1,p2);
        }
    }
    cout<<cost-mx;
    return 0;
}
