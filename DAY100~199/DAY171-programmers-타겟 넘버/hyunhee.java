class Solution {
    public int solution(int[] numbers, int target) {
       int answer = 0;
	        int temp =0;
	        int cur = 0;
	        return test(numbers, target, temp, cur, answer);
    }
    public int test(int[] numbers, int target, int temp, int cur, int ans) {
		
		if(cur==numbers.length) {
			if(temp == target)
				return ans+1;
			else return ans;
		}
		
			ans=test(numbers, target, temp+numbers[cur], cur+1, ans);
			ans=test(numbers, target, temp-numbers[cur], cur+1, ans);
		
		return ans;
		
	}
}