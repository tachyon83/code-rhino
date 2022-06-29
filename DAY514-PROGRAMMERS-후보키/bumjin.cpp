#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getBit(int x) {
    vector<int> v;
    int index = 0;
    while (x) {
        if (x % 2) v.push_back(index);
        x /= 2;
        index++;
    }
    return v;
}

int getBitCount(int x) {
    int ans = 0;
    while (x) {
        if (x % 2) ans++;
        x /= 2;
    }
    return ans;
}

bool compare(int A, int B) {
    return getBitCount(A) <= getBitCount(B);
}

int solution(vector<vector<string>> relation) {
    int N = relation.size(), M = relation[0].size();
    int maxSize = (1 << M);

    vector<int> bitMask;
    for (int i = 1; i < maxSize; i++) {
        vector<int> cols = getBit(i);
        
        bool isBit = true;
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                bool isDif = false;
                for (int l = 0; l < cols.size(); l++) {
                    if (relation[j][cols[l]] != relation[k][cols[l]]) {
                        isDif = true;
                    }
                }
                if (!isDif) 
                    isBit = false;
            }
        }
        if (isBit) bitMask.push_back(i);
    }
    
   sort(bitMask.begin(), bitMask.end(), compare);
    
    int ans = 0;
    for (int i = 0; i < bitMask.size(); i++) {
        bool isAns = true;
        for (int j = 0; j < i; j++) {
            if ((bitMask[i] & bitMask[j]) == bitMask[j]) isAns = false;
        }
        if (isAns) ans++;
    }
    return ans;
}
