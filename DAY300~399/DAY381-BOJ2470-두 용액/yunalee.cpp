#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
long long arr[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long start = 0;
    long long end = N - 1;
    long long diff = 987987987987;
    long long result[2] = {};

    sort(arr, arr + N);

    while (start < end) {
        long long tmp = abs(arr[start] + arr[end]);
        if (tmp < diff) {
            diff = tmp;
            result[0] = arr[start];
            result[1] = arr[end];
        }

        if (arr[start] + arr[end] > 0) {
            end--;
        }
        else {
            start++;
        }
    }

    cout << result[0] << ' ' << result[1] << '\n';

    return 0;

}
