#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=2e5;
int n,arr[sz];
vector<int>nv;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i];


    for(int i=0;i<n;++i){
        int idx=lower_bound(nv.begin(),nv.end(),arr[i])-nv.begin();
        if(idx==(int)nv.size())nv.push_back(arr[i]);
        else nv[idx]=arr[i];
    }
    cout<<n-(int)nv.size();
    return 0;
}
