import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int[][] sudoku = new int[9][9];
	static boolean[][][] check = new boolean[9][9][10];

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		for (int i = 0; i < 9; i++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = Integer.parseInt(str.nextToken());
				for (int k = 0; k < 0; k++) {
					check[i][k][sudoku[i][j]] = true;
					check[k][j][sudoku[i][j]] = true;
				}

			}
		}

		dfs();

		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				bw.write(sudoku[r][c] + " ");
			}
			bw.newLine();
		}

		bw.flush();
	}

	private static boolean dfs() {
		boolean flag = true;
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (sudoku[r][c] == 0) {
					flag = false;
				}
			}
		}
		if (flag) {
			return flag;
		}
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (sudoku[r][c] == 0) {

					for (int i = 1; i <= 9; i++) {
						if (!check[r][c][i]) {
							for (int k = 0; k < 9; k++) {
								check[r][k][i] = true;
								check[k][c][i] = true;
							}
							sudoku[r][c] = i;
							flag = dfs();
							if (flag) {
								return flag;
							}
							sudoku[r][c] = 0;
							for (int k = 0; k < 9; k++) {
								check[r][k][i] = false;
								check[k][c][i] = false;
							}

						}
					}

				}
			}
		}

		return flag;

	}

}