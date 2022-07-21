import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {
        // 배열의 과반수를 차지하는 원소 == 정렬 후에 정가운데에 있는 원소
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
