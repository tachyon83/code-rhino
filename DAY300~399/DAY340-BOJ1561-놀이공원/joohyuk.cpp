#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

const int sz=1e4;
int n,m,arr[sz],mn=2e9+1;
bool vis[sz];

int bs(){
    ll s=0,e=2e9*30+1,cnt=0,ret=0;
    while(s<e){
        cnt=0;
        ll mid=(s+e)/2;
        for(int i=0;i<m;++i){
            cnt+=mid/arr[i];
            if(mid%arr[i])cnt++;
        }
        if(cnt>=n) e=mid;
        else{
            if((n-cnt)<=m)ret=mid;
            s=mid+1;
        }
    }

    cnt=0;
    for(int i=0;i<m;++i){
        cnt+=ret/arr[i];
        if(ret%arr[i]){
            cnt++;
            vis[i]=1;
        }
    }
    return n-cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>arr[i];
        mn=min(mn,arr[i]);
    }
    if(n<=m){
        cout<<n;
        return 0;
    }

    int v=bs(),i=0;
    while(v){
        if(!vis[i]){
            v--;
            i++;
        }else i++;
    }
    cout<<i;
    return 0;
}
