package level3.단어변환;

import java.util.*;

class Solution_BFS2 {
	
	public static void main(String[] args) {
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log", "cog" }));
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log" }));
	}
	
	static class Point {
		String current;
		boolean[] check;
		int cnt;

		public Point(String current, boolean[] check, int cnt) {
			this.current = current;
			this.check = check;
			this.cnt = cnt;
		}
	}

	public static int solution(String begin, String target, String[] words) {
		int answer = 0;
		Queue<Point> queue = new LinkedList<>();
		boolean[] check = new boolean[words.length];
		Arrays.fill(check, false);
		int idx = 0;
		while (!words[idx].equals(target)) {
			idx++;
			if (idx == words.length)
				return answer;
		}
		for (int i = 0; i < words.length; i++) {
			int count = 0;
			for (int j = 0; j < begin.length(); j++) {
				if (begin.charAt(j) != words[i].charAt(j))
					count++;
			}
			if (count == 1) {
				check[i] = true;
				queue.offer(new Point(words[i], check, 1));
				check[i] = false;
			}
		}
		while (!queue.isEmpty()) {
			Point p = queue.poll();
			String current = p.current;
			if (current.equals(target)) {
				answer = p.cnt;
				break;
			}
			for (int i = 0; i < words.length; i++) {
				if (!check[i]) {
					int count = 0;
					for (int j = 0; j < begin.length(); j++) {
						if (current.charAt(j) != words[i].charAt(j))
							count++;
					}
					if (count == 1) {
						p.check[i] = true;
						queue.offer(new Point(words[i], p.check, p.cnt + 1));
						p.check[i] = false;
					}
				}
			}
		}

		return answer;
	}
}