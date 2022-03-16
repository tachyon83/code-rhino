#include <iostream>
#define endl '\n'
using namespace std;

const int sz=5e2+1;
int n,m,ct[sz][sz],t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i)fill(ct[i],ct[i]+n+1,n);
    while(m--){
        int a,b;
        cin>>a>>b;
        ct[a][b]=1;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                ct[i][j]=min(ct[i][j],ct[i][k]+ct[k][j]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        bool flag=0;
        for(int j=1;j<=n;++j){
            if(i==j)continue;
            if(ct[i][j]>=n&&ct[j][i]>=n){
                flag=1;
                break;
            }
        }
        if(!flag)t++;
    }
    cout<<t;
    return 0;
}
