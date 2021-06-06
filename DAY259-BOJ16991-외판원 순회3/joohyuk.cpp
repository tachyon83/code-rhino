#include <iostream>
#include <iomanip>
#include <cmath>
#define endl '\n'
#define ll long long
using namespace std;

const int big=8e4;
double dp[1<<16][16],mn=big;
int coords[16][2],n,complete;

double dist(int a,int b){
    int dx=coords[a][0]-coords[b][0];
    int dy=coords[a][1]-coords[b][1];
    return sqrt(dx*dx+dy*dy);
}

double tsp(int mask,int s){
    double& curr=dp[mask][s];
    if(curr!=big)return curr;
    if(mask==complete)return curr=dist(s,0);

    for(int i=0;i<n;++i){
        if(i==s || mask&(1<<i))continue;
        curr=min(curr,dist(s,i)+tsp(mask|(1<<i),i));
    }
    return curr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    complete=(1<<n)-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            dp[j][i]=big;
        }
    }
    for(int i=0;i<n;++i)cin>>coords[i][0]>>coords[i][1];
    cout<<fixed<<setprecision(6)<<tsp(1<<0,0);
    return 0;
}
