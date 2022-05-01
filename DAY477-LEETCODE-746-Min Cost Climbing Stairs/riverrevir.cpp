class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> m(cost.size() + 1);
        return dp(cost, m, cost.size());
    }
private:
    int dp(vector<int>& cost, vector<int>& m, int i) {
        if (i <= 1) return 0;        
        if (m[i] > 0) return m[i];
        return m[i] = min(dp(cost, m, i - 1) + cost[i - 1], 
                          dp(cost, m, i - 2) + cost[i - 2]);
    }
};
