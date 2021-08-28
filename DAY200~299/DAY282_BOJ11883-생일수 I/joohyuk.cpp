#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=1e6+5;
int dp[sz][2],t,n;
vector<int>nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    dp[0][0]=1;
    for(int i=0;i<sz;++i){
        if(!dp[i][0])continue;
        if(i+3<=sz&&(!dp[i+3][0]||dp[i][1]+1<dp[i+3][1])){
            dp[i+3][0]=3;
            dp[i+3][1]=dp[i][1]+1;
        }
        if(i+5<=sz&&(!dp[i+5][0]||dp[i][1]+1<dp[i+5][1])){
            dp[i+5][0]=5;
            dp[i+5][1]=dp[i][1]+1;
        }
        if(i+8<=sz&&(!dp[i+8][0]||dp[i][1]+1<dp[i+8][1])){
            dp[i+8][0]=8;
            dp[i+8][1]=dp[i][1]+1;
        }
    }
    dp[0][0]=0;

    cin>>t;
    while(t--){
        cin>>n;
        nums.clear();
        if(!dp[n][0]){
            cout<<-1<<endl;
            continue;
        }
        while(n){
            nums.push_back(dp[n][0]);
            n-=dp[n][0];
        }
        for(int i=nums.size()-1;i>-1;--i)cout<<nums[i];
        cout<<endl;
    }
    return 0;
}
