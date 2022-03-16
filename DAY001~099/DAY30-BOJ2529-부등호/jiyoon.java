import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2529 {
	static String[] op;

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(reader.readLine());
		op = reader.readLine().split(" ");

		printMax();
		printMin();

	}

	static void printMax() {
		int n = 0;
		int top = 9;
		for (int i = 0; i < op.length; i++) {
			if (op[i].equals(">")) {
				for (int j = top - n; j <= top; j++)
					System.out.print(j);
				top = top - n - 1; // 초기화
				n = 0; // 초기화
			} else if (op[i].equals("<")) {
				n++;
			}
		}
		for (int i = top - n; i <= top; i++)
			System.out.print(i);
		System.out.println();
	}

	static void printMin() {
		int n = 0;
		int top = 0;
		for (int i = 0; i < op.length; i++) {
			if (op[i].equals("<")) {
				for (int j = top + n; j >= top; j--)
					System.out.print(j);
				top = top + n + 1; // 초기화
				n = 0; // 초기화
			} else if (op[i].equals(">")) {
				n++;
			}
		}
		
		for (int i = top + n; i >= top; i--)
			System.out.print(i);
		System.out.println();
	}
}
