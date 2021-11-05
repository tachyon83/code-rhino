import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        Stack<Integer> s = new Stack<Integer>();
        List<Integer> answer = new ArrayList<Integer>();
        
        for(int i = progresses.length-1; i >= 0; i--) {
//        	올림 : ceil, 버림 : floor, 반올림 : round, 절대값 : abs 
        	s.add((int)Math.ceil((double)(100 - progresses[i])/(double)speeds[i]));
        }
        while(!s.isEmpty()) {
        	int cnt = 1; 
        	int top = s.pop();
        	while (!s.isEmpty() && s.peek() <= top) {
        		cnt++;
        		s.pop();
        	}
        	answer.add(cnt);
        }
        
        
        return answer;
    }
}
