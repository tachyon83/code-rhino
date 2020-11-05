#include <iostream>
#define endl '\n'
using namespace std;
const int sz=5e5+1;
int t,mn,hold,k,n,h,hits[sz],hits_rev[sz];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>h;
    for(int i=0;i<n;++i){
        cin>>k;
        if(i%2)hits_rev[h+1-k]++;
        else hits[k]++;
    }
    for(int i=h-1;i>0;--i){
        hits[i]+=hold;
        hold=hits[i];
    }
    hold=0;
    for(int i=1;i<=h;++i){
        hits_rev[i]+=hold;
        hold=hits_rev[i];
    }
    mn=n/2+1;
    for(int i=1;i<=h;++i){
        hits[i]+=hits_rev[i];
        if(hits[i]<mn){
            t=1;
            mn=hits[i];
        }else if(hits[i]==mn) t++;
    }
    cout<<mn<<' '<<t;
    return 0;
}
