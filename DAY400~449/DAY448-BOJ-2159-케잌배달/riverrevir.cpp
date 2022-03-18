#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define LINF 1e15
#define pii pair<int, int>
 
typedef long long ll;
// typedef pair<int, int> pii;
 
using namespace std;
 
struct POINT{
    pii coord; 
    ll d;
    int idx;
};
 
struct cmp{
    bool operator()(POINT &a, POINT &b){
        return a.d > b.d;
    }
};
 
int N;
pii rest[100001];
ll dist[100001][4];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
 
void input(){
    cin >> N >> rest[0].first >> rest[0].second;
    for(int i = 1; i <= N; i++){
        cin >> rest[i].first >> rest[i].second;
    }
    for(int i = 0; i < 100001; i++){
        for(int k = 0; k < 4; k++){
            dist[i][k] = LINF;
        }
    }
}
 
int distance(pii &a, pii &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
 
void Dijkstra(){
    priority_queue<POINT, vector<POINT>, cmp> pq;
    pq.push({rest[0], 0, 0});
    
    while(!pq.empty()){
        POINT now = pq.top();
        int next = now.idx+1;
        pq.pop();
        
        if(now.idx == N){
            cout << now.d << "\n";
            break;
        }
        
        for(int k = 0; k < 4; k++){
            pii np;
            np.first = rest[next].first + dr[k];
            np.second = rest[next].second + dc[k];
            ll next_dist = now.d + distance(now.coord, np);
            
            if(next_dist < dist[next][k]){
                pq.push({np, next_dist, next});
                dist[next][k] = next_dist;
            }
        }
    }
}
 
int main(){
    fastio
    input();
    Dijkstra();
    
    return 0;
}
//복습필요
