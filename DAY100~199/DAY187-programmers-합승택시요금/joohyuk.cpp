#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=200+1,big=200*1e5+1;
int d,curr,m=big*3,cost[sz];
vector<pii>g[sz];
priority_queue<pii,vector<pii>,greater<pii> > pq;

void dijkstra(int i,int s,int a,int b){
    fill(cost,cost+sz+1,big);
    cost[i]=0;
    pq.push(mp(cost[i],i));
    while(!pq.empty()){
        pii cp=pq.top();pq.pop();
        d=cp.first;curr=cp.second;
        if(d>cost[curr])continue;
        for(pii np:g[curr]){
            if(cost[np.first]>d+np.second){
                cost[np.first]=d+np.second;
                pq.push(mp(cost[np.first],np.first));
            }
        }
    }
    m=min(m,cost[s]+cost[a]+cost[b]);
}

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    s=s;a=a;b=b;
    for(vector<int> fare:fares){
        g[fare[0]].push_back(mp(fare[1],fare[2]));
        g[fare[1]].push_back(mp(fare[0],fare[2]));
    }
    for(int i=1;i<=n;++i)dijkstra(i,s,a,b);
    return m;
}
