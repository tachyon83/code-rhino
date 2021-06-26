#include <iostream>
#include <vector>
#define ll long long
#define endl '\n'
using namespace std;

const int sz=1<<20;
ll cnt;
vector<int>mst[sz];

void mergesort(int idx){
    vector<int>&larr=mst[idx<<1],rarr=mst[idx<<1|1];
    int i=0,j=0,isz=larr.size(),jsz=rarr.size(); 
    while(i<isz&&j<jsz){
        if(larr[i]>rarr[j]){
            cnt+=isz-i;
            mst[idx].push_back(rarr[j++]);
        }else mst[idx].push_back(larr[i++]);
    }
    while(i<isz)mst[idx].push_back(larr[i++]);
    while(j<jsz)mst[idx].push_back(rarr[j++]);
}
void solve(){
    for(int i=(sz>>1)-1;i>0;--i)mergesort(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,temp;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        mst[(sz>>1)+i].push_back(temp);
    }
    solve();
    cout<<cnt;
    return 0;
}
