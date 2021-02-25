import java.io.*;
import java.util.*;

class Solution {
	public int[] solution(String[] operations) {
		int[] answer = new int[2];
		
		ArrayDeque<Integer> queue = new ArrayDeque();
		
		int min = 0;
		int max = 0;
		
		// minPriorityQueue
		for (int i = 0; i < operations.length; i++) {
			String s[] = operations[i].split(" ");
			if (s[0].equals("I")) {
				int s1 = Integer.parseInt(s[1]);
				queue.addLast(s1);
				Integer[] temp = queue.toArray(new Integer[] {0});
				Arrays.sort(temp);
				queue.clear();
				for (int o : temp) {
				    queue.add(o);
				}
				
				
			} else if (s[0].equals("D") && queue.size()>0) {
				
				if (s[1].equals("1")) {
					queue.removeLast();
				} 
				else if (s[1].equals("-1")) {
                	queue.remove();
				}
			}
			
			
		}
		
		
		if (queue.size()>0) {
			min = queue.peek();
		}

		if (queue.size()>0) {
			max = queue.peekLast();
		}
		if(queue.size() <= 0){
            min = 0;
            max = 0;
        }
		
		answer[0] = max;
		answer[1] = min;
		
		
		return answer;
	}
}
