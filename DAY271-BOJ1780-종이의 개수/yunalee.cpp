#include <iostream>

using namespace std;

int arr[5000][5000];
int cnt[3];

bool sameChk(int x, int y, int n) {
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (arr[x][y] != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}
void solution(int x, int y, int n) {
    if (sameChk(x, y, n)) {
        cnt[arr[x][y]+1] += 1;
        return;
    }
    int m = n/3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            solution(x+i*m, y+j*m, m);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    
    solution(0, 0, N);
    
    for (int i=0; i<3; i++) {
        cout << cnt[i] << '\n';
    }
}
