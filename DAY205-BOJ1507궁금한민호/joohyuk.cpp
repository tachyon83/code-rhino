#include <iostream>
#define endl '\n'
using namespace std;

const int sz=20+1;
int r[sz][sz],rn[sz][sz],n,t;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>r[i][j];
            rn[i][j]=r[i][j];
            t+=r[i][j];
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==k||k==j||j==i)continue;
                if(r[i][j]==r[i][k]+r[k][j]){
                    if(rn[i][j])t-=r[i][j];
                    rn[i][j]=0;
                }else if(r[i][j]>r[i][k]+r[k][j]){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<t/2;
    return 0;
}
