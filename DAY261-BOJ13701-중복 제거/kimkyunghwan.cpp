#include <iostream>
using namespace std;
const int max_N = 1 << 20;

int arr[max_N];
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, idx, mask;
    while (cin >> n) {
        idx = n / 32;
        mask = 1 << (n % 32);
        if (arr[idx] & mask) continue;
        arr[idx] |= mask;
        cout << n << ' ';
    }
    return 0;
}
