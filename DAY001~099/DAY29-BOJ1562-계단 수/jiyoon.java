import java.util.Scanner;

public class BJ1562 {
	static final int M = 1000000000;
	static long[][][] 결과배열;

	static long 계단수(int 길이, int 앞자리, int 비트) {
		if (길이 <= 0)
			return 비트 == (1 << 10) - 1 ? 1 : 0;

		if (결과배열[길이][앞자리][비트] > 0)
			return 결과배열[길이][앞자리][비트];

		long 결과 = 0;
		if (앞자리 - 1 >= 0) {
			int bit = 비트 | (1 << (앞자리 - 1));
			결과 = (결과 + 계단수(길이 - 1, 앞자리 - 1, bit)) % M;
		}
		if (앞자리 + 1 <= 9) {
			int bit = 비트 | (1 << (앞자리 + 1));
			결과 = (결과 + 계단수(길이 - 1, 앞자리 + 1, bit)) % M;
		}

		return 결과배열[길이][앞자리][비트] = 결과;
	}

	static long solution(int N) {
		결과배열 = new long[N][10][1 << 10];

		long 결과 = 0;
		for (int i = 1; i <= 9; ++i) {
			결과 += (계단수(N - 1, i, 1 << i) % M);
			결과 %= M;
		}
		return 결과;
	}

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int N = scanner.nextInt();
			System.out.println(solution(N));
		}

	}
}
