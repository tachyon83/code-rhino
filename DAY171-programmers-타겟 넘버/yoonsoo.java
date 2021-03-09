class Solution {

    
       public static int dfs(int[] numbers,int target,int dept,int sum){
    	
        if(dept == numbers.length) {
          if(sum == target) {
            return 1;
          }else{
            return 0;
          }
    	
    	}
    	
        
        return dfs(numbers,target,dept+1,sum+numbers[dept])+dfs(numbers,target,dept+1,sum-numbers[dept]);
    	
    
    }
	
    public int solution(int[] numbers, int target) {
       
        
          
        int ans = dfs(numbers,target,0,0);
        
        
        return  ans;
    }
}
