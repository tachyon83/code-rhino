#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define ll long long
using namespace std;

const int sz=1e3;
int t,n,m,a[sz],b[sz],pv;
ll ans;
vector<int>va,vb;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]+=pv;
        va.push_back(a[i]);
        pv=a[i];
    }
    pv=0;
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>b[i];
        b[i]+=pv;
        vb.push_back(b[i]);
        pv=b[i];
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            va.push_back(a[i]-a[j]);
        }
    }
    for(int i=1;i<m;++i){
        for(int j=0;j<i;++j){
            vb.push_back(b[i]-b[j]);
        }
    }
    sort(vb.begin(),vb.end());

    for(int v:va){
        int i1=lower_bound(vb.begin(),vb.end(),t-v)-vb.begin();
        int i2=upper_bound(vb.begin(),vb.end(),t-v)-vb.begin();
        ans+=i2-i1;
    }
    cout<<ans;
    return 0;
}
