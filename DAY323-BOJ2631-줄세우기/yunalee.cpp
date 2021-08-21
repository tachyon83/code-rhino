#include <iostream>
#include <algorithm>

using namespace std;

int N;
int answer = 0;
int arr[201];
int dp[201];

void solution(){
    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        if(answer < dp[i]){
            answer = dp[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];

    }

    solution();

    answer = N - answer;

    cout << answer << '\n';
}
