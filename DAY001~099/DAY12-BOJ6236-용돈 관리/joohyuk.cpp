#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
const int sz=1e5+1;
int mx,n,m,spend[sz];
ll cnt,curr,s,e,mid;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>spend[i];
        mx=max(mx,spend[i]);
    }
    s=mx,e=1e9;
    while(s!=e){
        mid=(s+e)/2;
        cnt=1;
        curr=mid;
        for(int i=1;i<n;++i){
            while(curr<spend[i]){
                cnt++;
                curr+=mid;
            }
            curr-=spend[i];
            if(curr<spend[i+1]){
                cnt++;
                curr=mid;
            }
        }
        while(curr<spend[n]){
            cnt++;
            curr+=mid;
        }
        if(cnt>m)s=mid+1;
        else e=mid;
    }
    cout<<e<<endl;
    return 0;
}
