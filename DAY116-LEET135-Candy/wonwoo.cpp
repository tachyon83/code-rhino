class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (!size) {
            return 0;
        }

        vector<int> candy(size, 1);
        for (int i = 1; i < size; i++) {
            candy[i] = ratings[i] > ratings[i - 1] ? candy[i - 1] + 1 : candy[i];
        }

        int ans = 0;
        for (int i = size - 2; i >= 0; i--) {
            candy[i] = ratings[i + 1] < ratings[i] ? max(candy[i], candy[i + 1] + 1) : candy[i];
            ans += candy[i];
        }
        ans += candy[size - 1];
        return ans;
    }
};