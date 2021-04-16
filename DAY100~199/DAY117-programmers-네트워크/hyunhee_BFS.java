import java.util.LinkedList;
import java.util.Queue;

public class Solution {

//	public static void main(String[] args) {

//		int n = 3;
//		int[][] computers = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
//		System.out.println(solution(n, computers));
//		n = 3;
//		computers = new int[][] { { 1, 1, 0 }, { 1, 1, 1 }, { 0, 1, 1 } };
//		System.out.println(solution(n, computers));

//	}

	public int solution(int n, int[][] computers) {
		int answer = 0;
		Queue<Integer> queue = new LinkedList<>();
		for (int i = 0; i < computers.length; i++) {
			for (int j = 0; j < computers.length; j++) {
				if (computers[i][j] == 1) {
					computers[i][j] = 0;
					queue.offer(j);
					while (!queue.isEmpty()) {
						int s = queue.poll();
						for (int e = 0; e < computers.length; e++) {
							if (computers[s][e] == 1) {
								computers[s][e] = 0;
								computers[e][s] = 0;
								queue.offer(e);
							}
						}
					}
					queue.clear();
					answer++;
				}

			}
		}
		return answer;
	}

}
