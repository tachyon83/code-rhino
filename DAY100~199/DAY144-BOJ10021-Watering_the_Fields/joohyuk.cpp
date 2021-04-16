#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;
typedef long long ll;

const int sz=2000+1;
int n,c,x,y,roots[sz];
pair<int,int> coords[sz];
bool vis[sz];

struct Node {
    int cost, s, e;
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};
priority_queue<Node> pq;

int find(int a){
    if(roots[a]==a)return a;
    roots[a]=find(roots[a]);
    return roots[a];
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    roots[a]=b;
}

int costFinder(pair<int,int>pa,pair<int,int>pb){
    return pow(pa.first-pb.first,2)+pow(pa.second-pb.second,2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>c;
    for(int i=0;i<n;++i){
        roots[i]=i;
        cin>>x>>y;
        coords[i]=make_pair(x,y);
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            if(i!=j){
                int temp=costFinder(coords[i],coords[j]);
                if(temp<c)continue;
                Node node;
                node.cost=temp;
                node.s=i;
                node.e=j;
                pq.push(node);
            }
        }
    }
    ll t=0;
    while(!pq.empty()){
        Node curr=pq.top();pq.pop();
        if(find(curr.s)!=find(curr.e)){
            t+=curr.cost;
            merge(curr.s,curr.e);
        }
    }
    cout<<t;
    return 0;
}
