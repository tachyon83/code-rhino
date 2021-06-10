import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int T, N; 
//	result가 계속 더해주다보면 int범위 넘어갈지도..(같이 더하는 max와 stock도 long으로)
	static long result, stock[], max;
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < T; i++) {
			N = Integer.parseInt(br.readLine());
			stock = new long[N];
			max = 0;
			result = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int k = 0; k < N; k++) {
				stock[k] = Integer.parseInt(st.nextToken());
			}
			
//			뒤에서부터 계산 (최고치일 때를 찾아야 함)
			for(int j = N-1; j >= 0; j--) {
//				아무것도 하지 않는다.
				if(max <= stock[j]) {
					max = stock[j];
				}else {
//					(최고치 - 주식) 
					result += (max - stock[j]);
				}
			}
			System.out.println(result);
		}

	}

}
