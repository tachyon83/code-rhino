#include <iostream>
#include <queue>
#include <algorithm> //sort
#include <cstring> //memset, use 0 or -1
#define endl '\n'
using namespace std;
const int big=1000;
int box[big][big];
int r,c,t,qs,curr,cnt,day;
queue<pair<int,int>> q;
int dr[4]={0,1,0,-1};
int dc[4]={-1,0,1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>c>>r;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>curr;
            if(curr==1)
                q.emplace(make_pair(i,j));
            if(curr==0) cnt++;
            box[i][j]=curr;
        }
    }
    if(!cnt){
        cout<<0<<endl;
        return 0;
    }

    while(q.size()){
        qs=q.size();
        day++;
        for(int i=0;i<qs;i++){
            auto p=q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nr=p.first+dr[j];
                int nc=p.second+dc[j];
                if(nr<r && nr>=0 && nc<c && nc>=0 && box[nr][nc]==0){
                    q.emplace(make_pair(nr,nc));
                    box[nr][nc]=1;
                    cnt--;
                }
            }
        }
    }
    if(cnt) cout<<-1<<endl;
    else cout<<day-1<<endl;
    return 0;
}
