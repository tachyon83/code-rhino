#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int w[1000],n,pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=0;i<n;++i)cin>>w[i];
    sort(w,w+n);
    for(int i=0;i<n;++i){
        if(w[i]>pos+1)break;
        pos+=w[i];
    }
    cout<<pos+1;
    return 0;
}
