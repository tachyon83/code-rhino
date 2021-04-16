/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int num[21];
int count;

void solve(int index, int n, int *arr, int size) {
    int i, dis;

    if (count == n)
        return;
    
    if (*(arr + index)) {
        solve(index + 1, n, arr, size);
    }

    for (i = n ;i >= 1; i--) {
        dis = i == 1 ? 0 : i; //integer 1 occurs once
    
        if (num[i])
            continue;
        
        if (index + dis >= size)
            continue;
        
        if (*(arr + index + dis) != 0 || *(arr + index) != 0)
            continue;
        
        *(arr + index) = *(arr + index + dis) = i;
        num[i] = 1;
        count++;
        
        solve(index + 1, n, arr, size);
        
        if (count == n)
            return;
        
        *(arr + index) = *(arr + index + dis) = 0;
        num[i] = 0;
        count--;
    }
}

int* constructDistancedSequence(int n, int* returnSize){
    int *answer;
    *returnSize = (n - 1) * 2 + 1;
    answer = (int *)malloc(*returnSize * sizeof(int));
    
    memset(answer, 0, *returnSize * sizeof(int));
    memset(num, 0, 21 * sizeof(int));
    count = 0;
    solve(0, n, answer, *returnSize);
    
    return answer;
}
