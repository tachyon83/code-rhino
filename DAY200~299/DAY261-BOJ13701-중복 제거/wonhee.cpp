#include<iostream>
using namespace std;
int n, arr[1 << 20] = { 0 };

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n){
        int x = n / 32;
        int y = 1 << (n % 32);
        if (!(arr[x] & y)) {
            arr[x] += y;
            cout << n << ' ';
        }
    }
    return 0;
}