#include <queue>
#include <vector>
#include <iostream>
#define endl '\n'
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq,pqtemp;
int cnt,pos,s,e,mid,n,m,l,v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m>>l;
    for(int i=0;i<n;++i){
        cin>>v;
        pq.push(v);
    }
    pq.push(0);
    pq.push(l);
    s=1,e=l;
    while(s!=e){
        mid=(s+e)/2;
        cnt=0,pos=0;
        pqtemp=pq;
        while(!pqtemp.empty()){
            if(pos+mid<pqtemp.top()){
                cnt++;
                pos+=mid;
            }else if(pos+mid==pqtemp.top()){
                pos+=mid;
                pqtemp.pop();
            }else{
                pos=pqtemp.top();
                pqtemp.pop();
            }
        }
        if(pos+mid<l)cnt++;
        if(cnt<=m)e=mid;
        else s=mid+1;
    }
    cout<<s<<endl;
    return 0;
}
