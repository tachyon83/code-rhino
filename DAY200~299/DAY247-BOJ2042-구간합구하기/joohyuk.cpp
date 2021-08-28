#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

const int sz=1<<21;
ll n,m,k,seg[sz],a,b,c;

void construct(){
    for(int i=(sz>>1)-1;i>0;i--)seg[i]=seg[i<<1]+seg[i<<1|1];
}
void update(int i,ll v){
    i=(sz>>1)+i-1;
    seg[i]=v;
    i>>=1;
    while(i>0){
        seg[i]=seg[i<<1]+seg[i<<1|1];
        i>>=1;
    }
}
ll sum(int s,int e,int i,int j,int idx){
    if(s>j||e<i)return 0;
    if(s<=i&&j<=e)return seg[idx];
    int mid=(i+j)/2;
    return sum(s,e,i,mid,idx<<1)+sum(s,e,mid+1,j,idx<<1|1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>seg[(sz>>1)+i];
    construct();
    for(int i=0;i<(m+k);++i){
        cin>>a>>b>>c;
        if(a-1)cout<<sum(b,c,1,sz>>1,1)<<endl;
        else update(b,c);
    }
    return 0;
}
