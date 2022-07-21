class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<List<Integer>>();

        if(numRows == 0) {
            return answer;
        }
        
        List<Integer> sub1 = new ArrayList<Integer>();
        
        sub1.add(1);
        answer.add(sub1);
        
        if(numRows == 1) {
            return answer;
        }
        
        for (int i = 1; i < numRows; i++){
            List<Integer> sub2 = new ArrayList<Integer>();
            sub2.add(1);
            for (int j = 1; j < i; j++){
                List<Integer> prev = answer.get(i - 1);
                sub2.add(prev.get(j - 1) + prev.get(j));
            }
            sub2.add(1);
            answer.add(sub2);
        }
        return answer;
    }
}
