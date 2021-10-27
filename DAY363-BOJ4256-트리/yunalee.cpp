#include <iostream>

using namespace std;

int pre_order[1001];
int in_order[1001];
// int post_order[1001];
// int post_idx = 0;

void solved(int start, int end, int idx){
    for(int i = start; i < end; i++){
        if(in_order[i] == pre_order[idx]){
            solved(start, i, idx + 1);
            solved(i + 1, end, idx + i + 1 - start);
            cout << pre_order[idx] << ' ';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    int n;

    cin >> testcase;

    while(testcase--){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> pre_order[i];
        }
        for(int i = 0; i < n; i++){
            cin >> in_order[i];
        }

        solved(0, n, 0);
        cout << '\n';
    }
}
