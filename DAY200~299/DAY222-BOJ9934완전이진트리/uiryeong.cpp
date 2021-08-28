#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
queue<int> qt[11];
queue<int> q;
int K = 0, N = 0;
int tree[3000];
void preOrder(int node, int depth) {
    if(node > N) return;
    preOrder(2 * node, depth + 1);
    tree[node] = q.front();
    q.pop();
    qt[depth].push(tree[node]);
    preOrder(2 * node + 1, depth + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    int num;
    while(cin >> num) {
        q.push(num);
        N++;
    }
    preOrder(1, 0);
    for(int i = 0; i < 11; i++) {
        if(qt[i].empty()) break;
        while(!qt[i].empty()) {
            cout << qt[i].front() << " ";
            qt[i].pop();
        }
        cout << '\n';
    }
};
