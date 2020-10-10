import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2559 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

		int n = Integer.parseInt(tokenizer.nextToken());
		int k = Integer.parseInt(tokenizer.nextToken());

		int[] arr = new int[n];
		tokenizer = new StringTokenizer(reader.readLine());
		for (int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(tokenizer.nextToken());
		}

		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}

		int max = sum;
		for (int i = k; i < n; i++) {
			sum -= arr[i - k];
			sum += arr[i];
			max = Math.max(max, sum);
		}
		
		System.out.println(max);
	}
}
