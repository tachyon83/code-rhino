package Q135;

import java.util.Arrays;

public class Candy {

	public static void main(String[] args) {
		System.out.println(new Solution().candy1(new int[] { 1, 0, 2 }));
		System.out.println(new Solution().candy1(new int[] { 1, 2, 2 }));
		System.out.println(new Solution().candy1(new int[] { 1, 2, 87, 87, 87, 2, 1 }));
		System.out.println("-----------------------");
		System.out.println(new Solution().candy2(new int[] { 1, 0, 2 }));
		System.out.println(new Solution().candy2(new int[] { 1, 2, 2 }));
		System.out.println(new Solution().candy2(new int[] { 1, 2, 87, 87, 87, 2, 1 }));
	}

	static class Solution {
		/* 방법 1 : 2차원배열 */
		public int candy1(int[] ratings) {
			int N = ratings.length;
			int[][] candies = new int[2][N]; // [0] : 왼쪽->오른쪽 [1] : 오른쪽->왼쪽
			for (int i = 0; i < 2; i++) {
				Arrays.fill(candies[i], 1);
			}
			for (int i = 1; i < N; i++) {
				if (ratings[i - 1] < ratings[i]) {
					candies[0][i] = candies[0][i - 1] + 1;
				}
				if (ratings[N - i - 1] > ratings[N - i]) {
					candies[1][N - i - 1] = candies[1][N - i] + 1;
				}
			}
			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += Math.max(candies[0][i], candies[1][i]);
			}

			return sum;
		}

		/* 방법2 : 1차원배열로 줄이기 */
		public int candy2(int[] ratings) {
			int N = ratings.length;
			int[] candies = new int[N]; // [0] : 왼쪽->오른쪽 [1] : 오른쪽->왼쪽
			Arrays.fill(candies, 1);
			for (int i = 1; i < N; i++) {
				if (ratings[i - 1] < ratings[i]) {
					candies[i] = Math.max(candies[i - 1] + 1, candies[i]);
				}
				if (ratings[N - i - 1] > ratings[N - i]) {
					candies[N - i - 1] = Math.max(candies[N - i] + 1, candies[N - i - 1]);
				}
			}
			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += candies[i];
			}

			return sum;
		}
	}

}
