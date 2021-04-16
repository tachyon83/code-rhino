package level3.단어변환;

public class Solution_DFS {

	public static void main(String[] args) {
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log", "cog" }));
		System.out.println(solution("hit", "cog", new String[] { "hot", "dot", "dog", "lot", "log" }));
	}

	static boolean[] isVisited;
	static int answer;

	public static int solution(String begin, String target, String[] words) {
		answer = Integer.MAX_VALUE;
		isVisited = new boolean[words.length];
		dfs(begin, target, words, 0);

		return answer == Integer.MAX_VALUE ? 0 : answer;
	}

	private static void dfs(String cur, String target, String[] words, int cnt) {
		if (cnt >= answer) {
			return;
		}
		if (cur.equals(target)) {
			answer = Math.min(cnt, answer);
			return;
		}

		for (int i = 0; i < words.length; i++) {
			if (isVisited[i]) {
				continue;
			}
			int temp = 0;
			for (int j = 0; j < words[i].length(); j++) {
				if (words[i].charAt(j) != cur.charAt(j)) {
					temp++;
				}
			}
			if (temp == 1) {
				isVisited[i] = true;
				dfs(words[i], target, words, cnt + 1);
				isVisited[i] = false;
			}
		}

	}

}
