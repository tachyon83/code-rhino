#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
const int big=500*25*25+1;
int st=100,cr=500;
bool hvisited[25][25],vvisited[25][25];
int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1},hcost[25][25],vcost[25][25],np,nd;
priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>>pq;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int sz=board.size();
    for(int i=0;i<sz;++i)fill(hcost[i],hcost[i]+sz,big);
    for(int i=0;i<sz;++i)fill(vcost[i],vcost[i]+sz,big);
    hcost[0][0]=0;
    vcost[0][0]=0;

    pq.push(make_pair(hcost[0][0],make_pair(0,make_pair(0,0))));
    pq.push(make_pair(vcost[0][0],make_pair(1,make_pair(0,0))));
    
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        auto coord=curr.second.second;
        auto prv=curr.second.first;
        if(prv){
            if(hvisited[coord.first][coord.second])continue;
            hvisited[coord.first][coord.second]=1;
        }
        else{
            if(vvisited[coord.first][coord.second])continue;
            vvisited[coord.first][coord.second]=1;
        }
        for(int i=0;i<4;++i){
            int nr=coord.first+dr[i];
            int nc=coord.second+dc[i];

            if(nr>=0 && nr<sz && nc>=0 && nc<sz && !board[nr][nc]){
                if(i%2==prv){
                    np=curr.first+st;
                    nd=prv;
                    if(prv){
                        if(np<hcost[nr][nc]){
                            pq.push(make_pair(np,make_pair(nd,make_pair(nr,nc))));
                            hcost[nr][nc]=np;
                        }
                    }else{
                        if(np<vcost[nr][nc]){
                            pq.push(make_pair(np,make_pair(nd,make_pair(nr,nc))));
                            vcost[nr][nc]=np;
                        }
                    }
                }else{
                    np=curr.first+cr+st;
                    nd=(prv+1)%2;
                    if(prv){
                        if(np<hcost[nr][nc]){
                            pq.push(make_pair(np,make_pair(nd,make_pair(nr,nc))));
                            hcost[nr][nc]=np;
                        }
                    }else{
                        if(np<vcost[nr][nc]){
                            pq.push(make_pair(np,make_pair(nd,make_pair(nr,nc))));
                            vcost[nr][nc]=np;
                        }
                    }
                }
            }
        }
    }
    answer=min(hcost[sz-1][sz-1],vcost[sz-1][sz-1]);
    return answer;
}
