package Q948;

import java.util.Arrays;

//import java.util.Arrays;

public class BagOfTokens_second {

	public static void main(String[] args) {

		System.out.println(new Solution().bagOfTokensScore(new int[] { 100 }, 50));
		System.out.println(new Solution().bagOfTokensScore(new int[] { 100, 200 }, 150));
		System.out.println(new Solution().bagOfTokensScore(new int[] { 100, 200, 300, 400 }, 200));

	}

	static class Solution {

		public int bagOfTokensScore(int[] tokens, int P) {

			Arrays.sort(tokens);
			int max = 0, score = 0;
			int front = 0;
			int rear = tokens.length - 1;
			while (front <= rear) {
				if (P >= tokens[front]) {
					P -= tokens[front];
					score++;
					max = Math.max(score, max);
					front++;
				} else {
					if (score > 0) {
						P += tokens[rear];
						score--;
						rear--;
					} else {
						break;
					}
				}
			}

			return max;

		}

	}

}
