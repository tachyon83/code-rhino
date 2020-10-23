#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> vc[1000001];
vector<int> tVc[1000001];
bool visited[1000001];
int chkArr[1000001][2];


void DFS(int n) {

    visited[n] = true;

    for (int i = 0; i < vc[n].size(); i++) {

        int next = vc[n][i];

        if (!visited[next]){
            tVc[n].push_back(next);
            DFS(next);
        }
    }
}



int solution(int n, bool chk) {
    int& result = chkArr[n][chk];

    if (result != -1) {
        return result;
    }

    if (chk) {
        result = 1;
        for (int i = 0; i < tVc[n].size(); i++) {
            int next = tVc[n][i];
            result += min(solution(next, true), solution(next, false));
        }
    }
    else {
        result = 0;
        for (int i = 0; i < tVc[n].size(); i++) {
            int next = tVc[n][i];
            result += solution(next, true);
        }
    }
    return result;

}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int var1, var2;
        cin >> var1 >> var2;

        vc[var1].push_back(var2);
        vc[var2].push_back(var1);
    }

    memset(chkArr, -1, sizeof(chkArr));

    DFS(1);

    int result = min(solution(1, false), solution(1, true));
    cout << result << '\n';
}
