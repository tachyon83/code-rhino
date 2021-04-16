#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
const int big=1e5;
queue<int> q;
bool visited[big+1];

void emplacer(int temp){
    visited[temp]=true;
    q.emplace(temp);
    int tlp=2*temp;
    while(tlp && tlp<=big && !visited[tlp]){
        visited[tlp]=1;
        q.emplace(tlp);
        tlp*=2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t=0,qs,curr,flag=0;
    cin>>n>>k;
    q.emplace(n);
    visited[n]=1;
    int tlp=n*2;
    while(tlp && tlp<=big){
        q.emplace(tlp);
        visited[tlp]=1;
        tlp*=2;
    }
    
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
            if(temp>=0 && !visited[temp])emplacer(temp);
            
            temp=curr+1;
            if(temp<=big && !visited[temp])emplacer(temp);

            temp=curr*2;
            if(temp<=big && !visited[temp])emplacer(temp);
        }
        if(flag)break;
    }
    cout<<t-1<<endl;
    return 0;
}
