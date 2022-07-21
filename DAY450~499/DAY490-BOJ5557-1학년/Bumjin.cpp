#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

int N;
arr[101], cache[21][101];

// dp(val, idx): 현재까지의 계산값이 val이고 idx번째 수~마지막 수까지 고려할 때 만들 수 있는 등식의 수
dp(ll val, int idx) {
    if (idx == N-1) {
        if (val == arr[idx]) return 1;
        else return 0;
    }
    
    & ret = cache[val][idx];
    if (ret != -1) return ret;
    
    ret = 0;
    if (val+arr[idx] <= 20) ret += dp(val+arr[idx], idx+1);
    if (val-arr[idx] >= 0) ret += dp(val-arr[idx], idx+1);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    cout << dp(arr[0], 1);

    return 0;
}
