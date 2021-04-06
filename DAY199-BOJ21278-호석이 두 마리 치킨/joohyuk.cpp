#include <iostream>
#define endl '\n'
using namespace std;

const int sz=1e2+1,big=sz*(sz-1)/2+1;
vector<int>g[sz];
int n,m,a,b,r[sz][sz],t=big,aa,ab,s;

int add(int a,int b){
    int temp=0;
    for(int i=1;i<=n;++i)temp+=min(r[a][i],r[b][i]);
    return temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i)fill(r[i],r[i]+n+1,big);
    for(int i=1;i<=n;++i)r[i][i]=0;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        r[a][b]=1;
        r[b][a]=1;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i==j||j==k||k==i)continue;
                r[i][j]=min(r[i][j],r[i][k]+r[k][j]);
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            s=add(i,j);
            if(t>s){
                t=s;
                aa=i,ab=j;
            }
        }
    }
    cout<<aa<<' '<<ab<<' '<<t*2<<endl;
    return 0;
}
