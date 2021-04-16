#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

const int sz=1000+5;
int t=-1,s,curr=1;
bool vis[sz][sz];
queue<pair<int,int> >q;

void checkThenPush(int n,int c){
    if(!vis[n][c]){
        vis[n][c]=1;
        q.push(make_pair(n,c));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>s;
    vis[curr][0]=1;
    q.push(make_pair(curr,0));
    while(!q.empty()){
        int qs=(int)q.size();
        t++;
        for(int i=0;i<qs;++i){
            auto cp=q.front();q.pop();
            if(cp.first==s){
                cout<<t;
                return 0;
            }
            checkThenPush(cp.first,cp.first);
            if(cp.second && cp.first+cp.second<=s)checkThenPush(cp.first+cp.second,cp.second);
            if(cp.first)checkThenPush(cp.first-1,cp.second);
        }
    }
    return 0;
}
