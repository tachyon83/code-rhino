#include <iostream>
#include <cmath>
#define endl '\n'
#define ll long long
using namespace std;

const int sz=20;
int cubes[sz];
bool flag;

ll solve(int l,int w,int h){
    if(l<=0||w<=0||h<=0)return 0;
    int i=(int)log2(min(l,min(w,h)));
    while(i>=0){
        if(cubes[i]){
            cubes[i]--;
            return 1+solve(l-(1<<i),w,1<<i)+solve(1<<i,w-(1<<i),1<<i)+solve(l,w,h-(1<<i));
        }
        i--;
    }
    flag=1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int l,w,h,a,b,t;
    cin>>l>>w>>h>>t;
    while(t--){
        cin>>a>>b;
        cubes[a]=b;
    }
    ll cnt=solve(l,w,h);
    if(flag)cnt=-1;
    cout<<cnt;
    return 0;
}
