class Solution {
    public int candy(int[] ratings) {
        int rl = ratings.length;
		int candies [] = new int[rl];
		
		candies[0] = 1;
		
		for(int i=1;i<rl;i++) {
			if(ratings[i-1] < ratings[i]) {	//오르막
				candies[i] = candies[i-1]+1;
			}
            else {
				candies[i] = 1;
			}
		}
		
		for(int i=rl-1;i>0;i--) {
			if((ratings[i-1] > ratings[i]) &&(candies[i] >= candies[i-1])) {
					candies[i-1] = candies[i]+1;
			}
		}
		
		
		int sum=0;
        
		for(int m=0;m<rl;m++){
			sum += candies[m];
		}
        
		return sum;
    }
}
