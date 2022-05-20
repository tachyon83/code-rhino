#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
#pragma warning(disable:4996)
#define INF 987654321
int main() {
    int n; scanf("%d", &n);
    vector<int> num_vec(n + 1, 987654321), ascend_vec;
    for (int n_idx = 1; n_idx <= n; n_idx++)
        scanf("%d", &num_vec[n_idx]);
    
    int n_idx = 1;
    ascend_vec.push_back(num_vec[n_idx++]);
    for (n_idx = 2; n_idx <= n; n_idx++){
        auto idx = lower_bound(ascend_vec.begin(), ascend_vec.end(), num_vec[n_idx]);
        // 현재 벡터에서 가장 큰 수보다 더 크면, 삽입
        if (idx == ascend_vec.end())
            ascend_vec.push_back(num_vec[n_idx]);
        // 현재 벡터에서 가장 큰 수보다 적으면, 
        // 해당 숫자보다 큰 요소들 중 가장 작은 요소 대신에 삽입 
        else
            *idx = num_vec[n_idx];
    }
    printf("%d", ascend_vec.size());
    return 0;
}
