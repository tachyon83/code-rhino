#include <iostream>

using namespace std;

const int MAX = 10001;
int arr[MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int sum = 0;
    int result = 0;

    while (end <= N) {
        if (sum >= M) {
            sum -= arr[start++];
        }
        else if (sum < M) {
            sum += arr[end++];
        }

        if (sum == M) {
            result++;
        }
    }

    cout << result << "\n";

    return 0;

}
