import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ2470 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(reader.readLine());
		int[] arr = new int[n];

		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

		for (int i = 0; i < n; i++) { 
			arr[i] = Integer.parseInt(tokenizer.nextToken());
		}

		Arrays.sort(arr); 
		
		
		int[] dp = new int[n - 1];
		
		int pL = 0; 
		int pR = n - 1; 

		int result = arr[pL] + arr[pR]; 
		int resultPL = arr[pL]; 
		int resultPR = arr[pR]; 

		for (int i = 0; i < n - 1; i++) {
			dp[i] = arr[pL] + arr[pR];

			if (Math.abs(dp[i]) < Math.abs(result)) { 
				result = dp[i];
				resultPL = arr[pL];
				resultPR = arr[pR];
			}
			
			if (dp[i] > 0) {
				pR--;
			} else if (dp[i] < 0) {
				pL++;
			} else { // 두 용액의 합이 0이면 for문을 종료
				break;
			}
		}
		// 결과 출력
		System.out.println(resultPL + " " + resultPR);
	}
}
