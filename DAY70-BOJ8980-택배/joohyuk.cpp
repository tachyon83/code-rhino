#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

struct Box {
    int a, b, c;
    bool operator<(const Box &n) const {
        if(a!=n.a)return a>n.a;
        return b>n.b;
    }
};
const int sz=2e3+1;
int mx,n,m,limit,hold,diff;
priority_queue<Box>pq;
vector<int>plans[sz];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>limit>>m;
    while(m--){
        Box temp;
        cin>>temp.a>>temp.b>>temp.c;
        temp.c=min(limit,temp.c);
        pq.push(temp);
    }
    for(int vn=1;vn<=n;++vn){
        for(int&c:plans[vn]){
            hold-=c;
            mx+=c;
        }
        while(!pq.empty()&&pq.top().a<=vn){            
            Box curr=pq.top();pq.pop();
            bool flag=0;
            for(int v=n;v>curr.b && curr.c>(limit-hold);--v){
                for(int&c:plans[v]){
                    diff=limit-hold;
                    if(curr.c<=diff){
                        flag=1;
                        break;
                    }
                    if(curr.c>diff+c){
                        hold-=c;
                        c=0;
                    }else{
                        hold-=curr.c-diff;
                        c-=curr.c-diff;
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(curr.c>limit-hold)curr.c=limit-hold;
            plans[curr.b].push_back(curr.c);
            hold+=curr.c;
        }
    }
    cout<<mx;
    return 0;
}
