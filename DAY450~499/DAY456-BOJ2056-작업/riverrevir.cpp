#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void) {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
 
    vector<int> finish_time(N + 1);
    vector<int> spend_time(N + 1);
    vector<vector<int>> parent_node(N + 1);
    // input
    for (int n_idx = 1; n_idx <= N; n_idx++) {
        int K;
        cin >> spend_time[n_idx] >> K;
        while (K--) {
            int sub_parent;
            cin >> sub_parent;
            parent_node[n_idx].push_back(sub_parent);
        }
    }
    // 부모 노드의 값을 보고 각각을 갱신 
    for (int n_idx = 1; n_idx <= N; n_idx++) {
        int parent_size = parent_node[n_idx].size();
        int parent_time_max = 0;
        for (int par_idx = 0; par_idx < parent_size; par_idx++)
            if(parent_time_max < finish_time[parent_node[n_idx][par_idx]])
                parent_time_max = finish_time[parent_node[n_idx][par_idx]]; 
 
        finish_time[n_idx] = parent_time_max + spend_time[n_idx];
    } 
    // 최대값 취하기
    int max_time = 0 ; 
    for (int n_idx = 1; n_idx <= N; n_idx++)
        if (max_time < finish_time[n_idx])
            max_time = finish_time[n_idx];
 
    cout << max_time;
    return 0;
}
