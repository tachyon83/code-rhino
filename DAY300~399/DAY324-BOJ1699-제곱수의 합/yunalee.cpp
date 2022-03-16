#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if(N < 4){
        cout << N << '\n';
        return 0;
    }
    
    for(int i = 1; i <= N; i++){
        dp[i] = i;
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);  // j^2의 1가지 경우를 +1 해준거다
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
