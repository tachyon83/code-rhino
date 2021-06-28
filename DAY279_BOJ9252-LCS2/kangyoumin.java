import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int[][] memo = new int[1001][1001];
	static char[] str1 = new char[1001];
	static char[] str2 = new char[1001];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str1 = br.readLine().toCharArray();
		str2 = br.readLine().toCharArray();
		int n = str1.length;
		int m = str2.length;


		System.out.println(getLCSLength(n, m));
		System.out.println(getLcsStr(n, m));
	}

	public static int getLCSLength(int n, int m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (str1[i - 1] == str2[j - 1])
					memo[i][j] = memo[i - 1][j - 1] + 1;
				else
					memo[i][j] = Math.max(memo[i][j - 1], memo[i - 1][j]);
			}
		}
		
		
		return memo[n][m];
	}
	
	public static String getLcsStr(int n, int m) {
		if(n == 0 || m == 0) {
			return "";
		} else if(str1[n-1] == str2[m-1]) {
			return getLcsStr(n-1, m-1) + str1[n-1];
		} else {
			if(memo[n][m-1] > memo[n-1][m])
				return getLcsStr(n, m-1);
			else
				return getLcsStr(n-1, m);
		}
	}
}
