import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static int num, sumTime=0, result = 0;
	private static int[] time;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		num = Integer.parseInt(br.readLine());
		time = new int[num];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < num; i++) {
			time[i] = Integer.parseInt(st.nextToken());
		}
		// 오름차순으로 정렬
		Arrays.sort(time);
		
		for (int i = 0; i < num; i++) {
			//각 사람이 돈 인출시 필요 시간 : 앞에 사람꺼 더한 시간들
			sumTime += time[i];
			//앞 사람들 인출 시간 + 내 인출시간
			result += sumTime;
			
		}
		System.out.println(result);
	}

}
