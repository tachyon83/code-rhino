class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k]; // 정렬 후 뒤에서 k번째 출력
    }
};
