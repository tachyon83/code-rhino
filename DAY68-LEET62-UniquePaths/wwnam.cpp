class Solution {
public:
    long long permute(int s, int e) {
        long long result = 1;
        for (int i = s + 1; i <= e; i++) {
            result *= i;
        }
        return result;
    }
    long long uniquePaths(long long m, long long n) {
        m--;
        n--;

        long long ans;
        if (n > m) {
            ans = permute(n, m + n) / permute(1, m);
        }
        else {
            ans = permute(m, m + n) / permute(1, n);
        }

        return ans;
    }
};