import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] weight = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			weight[i] = Integer.parseInt(st.nextToken());
		}
//		오름차순으로 정렬
		Arrays.sort(weight);
		
//		처음이 1이 아닌경우 무조건 1이 최소
		if(weight[0] != 1) {
			System.out.println(1);
			return;
		}
		
		int sum = weight[0];
		for(int i = 1; i < n; i++) {
//			크면 그 1만큼더한 값이 최소
			if(weight[i] > sum+1) break;
			sum += weight[i];
		}
		
		System.out.println(sum+1);
		
	}

}
