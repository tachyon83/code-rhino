#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int arr[9][9];
vector<pair<int, int>> v;
int cnt;
bool flag = false;
bool check(pair<int, int> p) {
    int x = p.first / 3;
    int y = p.second / 3;
    //cout << p.first << ' ' << p.second << '\n';
    //for (int i = 0; i < 9; i++) {
    //    for (int j = 0; j < 9; j++) {
    //        cout << arr[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
    //cout << '\n';
 
    for (int i = 0; i < 9; i++) {
        if (p.second != i && arr[p.first][p.second] == arr[p.first][i]) {
            return false;
        }
        if (p.first != i && arr[p.first][p.second] == arr[i][p.second]) {
            return false;
        }
    }

    for (int i = 3 * x; i < 3 * x + 3; i++) {
        for (int j = 3 * y; j < 3 * y + 3; j++) {
            if (i == p.first && j == p.second)continue;
            if (arr[i][j] == arr[p.first][p.second]) {
                return false;
            }
        }
    }

    return true;
}
void go(int n) {
    //for (int i = 0; i < 9; i++) {
    //    for (int j = 0; j < 9; j++) {
    //        cout << arr[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';
    if (n == cnt) { // 스도쿠 완성될 때
        flag = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        arr[v[n].first][v[n].second] = i; // 빈칸에 1~9까지 넣어봄
        if (check(v[n])) {
            go(n + 1);
        }
        if (flag) return;
    }
    arr[v[n].first][v[n].second]=0;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                cnt++;
                v.push_back({ i,j });
            }
        }
    }
    go(0);
}
