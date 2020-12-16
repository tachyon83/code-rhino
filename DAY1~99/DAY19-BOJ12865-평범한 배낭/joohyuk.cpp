#include <iostream>
#define endl '\n'
using namespace std;
const int wt=1e5+1;
int mx,knapsack[100][wt],given[100][2],n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>k;
    // W,V
    for(int i=0;i<n;++i)cin>>given[i][0]>>given[i][1];
    for(int i=0;i<n;++i){
        for(int j=0;j<=k;++j){
            if(given[i][0]<=j){
                if(!i)knapsack[i][j]=given[i][1];
                else knapsack[i][j]=max(knapsack[i-1][j-given[i][0]]+given[i][1],knapsack[i-1][j]);
                mx=max(mx,knapsack[i][j]);
            }else if(i)knapsack[i][j]=knapsack[i-1][j];
        }
    }
    cout<<mx<<endl;
    return 0;
}
