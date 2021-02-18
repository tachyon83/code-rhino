import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {

	public int solution(String name) {
		int answer = 0;

		char[] input = name.toCharArray();
		char[] output = new char[name.length()];
		Arrays.fill(output, 'A');

		PriorityQueue<int[]> idxList = new PriorityQueue<>(new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				return o2[1] - o1[1];
			}

		}); // [0] : idx, [1] : count
		int count = 0, startIdx = 0;
		for (int i = 0; i < input.length; i++) {
			if (input[i] == output[i]) {
				if (count > 0) {
					idxList.offer(new int[] { startIdx, count });
					count = 0;
				}
				startIdx = i + 1;
			} else {
				count++;
			}
		}
		int pre = 0;
		while(!idxList.isEmpty()) {
			
			int[] next = idxList.poll();
			for(int i=0;i<next[1];i++) {
				
			}
		}


		return answer;

	}


	private boolean check(char[] input, char[] output) {
		for (int i = 0; i < input.length; i++) {
			if (input[i] == output[i]) {
				continue;
			}
			return false;
		}
		return true;
	}

}
