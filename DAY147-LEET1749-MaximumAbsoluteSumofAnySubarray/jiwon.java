//왜 이렇게 되는지 이유를 모르겠음 ㅠㅠ 
class Solution {
    public int maxAbsoluteSum(int[] nums) {
     
        int max = 0; int min = 0;
        int sum = 0;
        
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
            min = Math.min(sum, min);
            max = Math.max(sum, max);
        }
        
        
        return max-min;
    }
}
