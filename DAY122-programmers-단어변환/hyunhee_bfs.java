package level3.단어변환;

import java.util.*;

class Solution_BFS {

	public static void main(String[] args) {
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log", "cog" }));
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log" }));
	}

	static class Point {
		char[] word;
		int count;

		public Point(char[] word, int count) {
			this.word = word;
			this.count = count;
		}

	}

	public static int solution(String begin, String target, String[] words) {

		Queue<Point> queue = new LinkedList<>();
		char[] temp = begin.toCharArray();
		queue.offer(new Point(temp, 0));

		boolean[] isVisited = new boolean[words.length];

		while (!queue.isEmpty()) {

			Point p = queue.poll();
			String answer = "";
			for (int i = 0; i < p.word.length; i++) {
				answer += p.word[i];
			}
			if (answer.equals(target)) {
				return p.count;
			}

			for (int i = 0; i < words.length; i++) {
				if (isVisited[i]) {
					continue;
				}
				temp = words[i].toCharArray();
				if (check(p.word, temp)) {
					queue.offer(new Point(temp, p.count + 1));
					isVisited[i] = true;
				}
			}

		}

		return 0;

	}

	private static boolean check(char[] word, char[] target) {
		int cnt = 0;
		for (int i = 0; i < target.length; i++) {
			if (word[i] != target[i]) {
				cnt++;
			}
		}
		return cnt == 1;
	}
}