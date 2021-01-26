class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();

        if (k == 1) {
            return true;
        }
        if (size % k) {
            return false;
        }

        sort(nums.begin(), nums.end());

        map<int, int> mp;
        for (int i = 0; i < size; i++) {
            mp[nums[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            if (mp[num - 1] == 0 && mp[num] > 0) {
                int copyK = k;
                while (k > 0) {
                    if (mp[num] > 0) {
                        mp[num]--;
                    }
                    else {
                        return false;
                    }

                    num++;
                    k--;
                    cnt++;
                }
                k = copyK;
            }
        }

        return cnt == size;
    }
};