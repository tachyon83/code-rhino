#include <iostream>
#include <queue>
#include <stack>
#define endl '\n'
using namespace std;
const int big=1e5;
queue<int> q;
bool visited[big+1];
int prv[big+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t=0,qs,curr,flag=0;
    cin>>n>>k;
    fill(prv,prv+n+1,-1);
    q.emplace(n);
    visited[n]=true;
    
    while(q.size()){
        qs=q.size();
        t++;
        for(int i=0;i<qs;i++){
            curr=q.front();
            if(curr==k){
                flag=1;
                break;
            }
            q.pop();
            int temp=curr-1;
            if(temp>=0){
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.emplace(temp);
                    prv[temp]=curr;
                }
            }
            temp=curr+1;
            if(temp<=big) {   
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.emplace(temp);
                    prv[temp]=curr;
                }
            }
            temp=curr*2;
            if(temp<=big) {
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.emplace(temp);
                    prv[temp]=curr;
                }
            }
        }
        if(flag)break;
    }
    cout<<t-1<<endl;
    stack<int>ans;
    ans.push(k);
    while(prv[k]!=-1){
        ans.push(prv[k]);
        k=prv[k];
    }
    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
    return 0;
}
