import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[][] B, A;
	static int R, C, X, Y;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		R = Integer.parseInt(str.nextToken());
		C = Integer.parseInt(str.nextToken());
		X = Integer.parseInt(str.nextToken());
		Y = Integer.parseInt(str.nextToken());

		A = new int[R][C];
		B = new int[R + X][C + Y];

		for (int h = 0; h < R + X; h++) {
			str = new StringTokenizer(br.readLine(), " ");
			for (int w = 0; w < C + Y; w++) {
				B[h][w] = Integer.parseInt(str.nextToken());
			}
		}

		for (int r = 0; r < R + X; r++) {
			for (int c = 0; c < C + Y; c++) {
				if (isIn(r, c) && !isIn(r - X, c - Y)) {
					A[r][c] = B[r][c];
				} else if (!isIn(r, c) && isIn(r - X, c - Y)) {
					A[r - X][c - Y] = B[r][c];
				} else {
					continue;
				}
			}
		}

		for (int r = 0; r < R + X; r++) {
			for (int c = 0; c < C + Y; c++) {
				if (isIn(r, c) && isIn(r - X, c - Y)) {
					A[r][c] = A[r][c] == 0 ? B[r][c] - A[r - X][c - Y] : A[r][c];
					A[r - X][c - Y] = A[r - X][c - Y] == 0 ? B[r][c] - A[r][c] : A[r - X][c - Y];
				} else if (!isIn(r, c) && isIn(r - X, c - Y)) {
					A[r - X][c - Y] = B[r][c];
				} else {
					continue;
				}
			}
		}

		for (int r = 0; r < R; r++) {
			for (int c : A[r]) {
				System.out.print(c + " ");
			}
			System.out.println();
		}

	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < R && c >= 0 && c < C;
	}

}