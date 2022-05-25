#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[100];
long long dp[100][21] = {0};

long long solve(){
  dp[0][arr[0]] = 1;

  for (int i=1; i<n-1; i++)
    for (int val=0; val<21; val++){
      if (dp[i-1][val]){
        if (val+arr[i] <= 20) dp[i][val+arr[i]] += dp[i-1][val];
        if (val-arr[i] >= 0) dp[i][val-arr[i]] += dp[i-1][val];  
      }
    }
  
  return dp[n-2][arr[n-1]];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> n;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}
