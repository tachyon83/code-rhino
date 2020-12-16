#include <iostream>
#include <queue>
#include <algorithm> //sort
#include <cstring> //memset, use 0 or -1
#define endl '\n'
using namespace std;
const int big=100000;
queue<int> q;
bool visited[big+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t=0,qs,curr,flag=0;
    cin>>n>>k;
    q.emplace(n);
    
    while(q.size()){
        qs=q.size();
        t++;
        for(int i=0;i<qs;i++){
            curr=q.front();
            visited[n]=true;
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
                }
            }
            temp=curr+1;
            if(temp<=big) {   
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.emplace(temp);
                }
            }
            temp=curr*2;
            if(temp<=big) {
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.emplace(temp);
                }
            }
        }
        if(flag)break;
    }
    cout<<t-1<<endl;
    return 0;
}
