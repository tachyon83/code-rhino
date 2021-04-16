class Solution {
    public int shipWithinDays(int[] weights, int D) {
        
        int answer = -1;
        for(int i=0;i<weights.length;i++){
            answer = Math.max(answer, weights[i]);
        }
        boolean flag = false;
        while(!flag){
            int d = 1, sum = 0;
            for(int i=0;i<weights.length;i++){
                sum += weights[i];
                if(sum > answer){
                    d++;
                    sum = weights[i];
                }
            }
            if(d==D){
                flag = true;
            } else if(d>D){
                answer++;
            } else {
                answer--;
            }
        }
        
        return answer;
        
    }
}