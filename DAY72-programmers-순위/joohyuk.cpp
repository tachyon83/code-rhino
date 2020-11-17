#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int sz = 100 + 1;
int cost[sz];
vector<int> g1[sz], g2[sz];
bool visited[sz];

int cntVisited(int n){
    int ret=0;
    for(int i=1;i<=n;++i)if(visited[i])ret++;
    return ret;
}

void DFS1(int a){
    visited[a]=1;
    for(int&nx:g1[a])if(!visited[nx])DFS1(nx);
}
void DFS2(int a){
    visited[a]=1;
    for(int&nx:g2[a])if(!visited[nx])DFS2(nx);
}

int solution(int n, vector<vector<int> > results)
{
    for (auto game : results)
    {
        g1[game[0]].push_back(game[1]);
        g2[game[1]].push_back(game[0]);
    }
    int ans=0;
    for (int i = 1; i <= n; ++i)
    {
        int temp=0;
        fill(visited,visited+1+n,0);
        DFS1(i);
        temp+=cntVisited(n);
        fill(visited,visited+1+n,0);
        DFS2(i);
        temp+=cntVisited(n);
        temp--;
        if(temp==n)ans++;
    }
    return ans;
}
