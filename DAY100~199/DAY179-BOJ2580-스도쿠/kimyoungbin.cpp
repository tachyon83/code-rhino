#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define LEN 9

int cnt = 0;
bool flag = false;
int board[LEN][LEN];
vector<pair<int, int>> blank;
bool check(pair<int,int> p ) {
    int sr = (p.first / 3) * 3;
    int er = (p.first / 3) * 3 + 3;
    int sc = (p.second / 3) * 3;
    int ec = (p.second / 3) * 3 + 3;
    for (int i = 0; i < LEN; ++i) {
        if (board[p.first][i] == board[p.first][p.second] && i != p.second)
            return false;
        if (board[i][p.second] == board[p.first][p.second] && i != p.first)
            return false;
    }
    for (int i = sr; i < er; ++i) {
        for (int j = sc; j < ec; ++j) {
            if (board[i][j] == board[p.first][p.second] && i != p.first && j != p.second)
                return false;
        }
    }
    return true;
}

void solve(int n) {
    if (n == cnt) {
        for (int i = 0; i < LEN; ++i) {
            for (int j = 0; j < LEN; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        flag = true;
        return;
    }
    for (int i = 1; i <= LEN; ++i) {
        board[blank[n].first][blank[n].second] = i;
        if (check(blank[n]))
            solve(n + 1);
        if (flag)
            return;
    }
    board[blank[n].first][blank[n].second] = 0;
}

int main() {
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            cin >> board[i][j];
            if (!board[i][j]) {
                ++cnt;
                blank.push_back(make_pair(i, j));
            }
        }
    }
    solve(0);
    return 0;
}
