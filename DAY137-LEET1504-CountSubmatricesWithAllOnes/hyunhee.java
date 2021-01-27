class Solution {
    public int numSubmat(int[][] mat) {
        int answer = 0;
			int R = mat.length;
			int C = mat[0].length;
			int K = Math.max(R, C);

			for (int r = 0; r < R; r++) {
				for (int c = 1; c < C; c++) {
					if (mat[r][c] != 0) {
						mat[r][c] += mat[r][c - 1]; // r행c열까지 갔을 때 만들 수 있는 1로 구성된 submatrix 갯수
					}
				}
			}

			int count = 0;
			for (int k = 0; k < K; k++) { // 열을 1개 봤을 때, 2개 봤을 떄, ...
				for (int c = 0; c + k < C; c++) { // 현재 행부터 k개의 행을 확인할 것
					for (int r = 0; r < R; r++) {
						if (mat[r][c + k] >= k + 1) {
							count++;
						} else {
							answer += (count * (count + 1)) / 2;
							count = 0;
						}
					}
					answer += (count * (count + 1)) / 2;
					count = 0;
				}
			}
			return answer;
        
    }
}