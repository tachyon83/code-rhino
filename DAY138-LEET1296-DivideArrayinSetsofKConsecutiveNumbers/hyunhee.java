class Solution {
    public boolean isPossibleDivide(int[] nums, int K) {
        if (nums.length % K != 0) {
				return false;
			}
			Arrays.sort(nums);
			Map<Integer, Integer> map = new HashMap<>();
			for (int i = 0; i < nums.length; i++) {
				int count = map.getOrDefault(nums[i], 0);
				map.put(nums[i], count + 1);
			}
			for (int i = 0; i < nums.length; i++) {
				int min = map.get(nums[i]);	// 얘가 시작하는 숫자
				if (min > 0) {
					for (int k = 1; k < K; k++) {
						min = Math.min(map.getOrDefault(nums[i] + k, -1), min);
                        if(min<=0){
                            return false;
                        }
					}
					if (min > 0) {
						for (int k = 0; k < K; k++) {
							map.put(nums[i] + k, map.get(nums[i] + k) - min);
						}
					}
				}
			}
			for (int i = 0; i < nums.length; i++) {
				if (map.get(nums[i]) != 0) {
					return false;
				}
			}
			return true;
    }
}