import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, max = 0;
	static int[] rope;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		rope = new int[N];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			rope[i] = Integer.parseInt(st.nextToken());
		}
		
//		정렬해주기
		Arrays.sort(rope);
//		첫번째 로프길이*로프개수는 max의 초기값
		max = rope[0] * N;
		
		for(int i = 1; i < rope.length; i++) {
//			로프의 개수는 점점 줄어든다
			N--;
			int weight = rope[i] * N;
//			max보다 클때
			if(max < weight)
				max = weight;
		}
		
		System.out.println(max);

	}

}
