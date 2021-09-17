import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	private static long getTime(int n, int m, int[] arr) {
		
		long start = 0;
		long end = 2000000000 * 30L;
		long result = 0;
		while(start < end) {
			
			long mid = (start + end) / 2;
			long people = m;
			for(int i = 0; i < m; i++) {
				people += (mid / arr[i]);
			}
			if(people >= n) {
				result = mid;
				end = mid;
			} else {
				start = mid + 1;
			}
		}
		return result;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[m];
		st = new StringTokenizer(input.readLine());
		for(int i = 0; i < m; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		int result = n;
		if(n > m) {
			
			//만족할 수 있는 시간을 구하고
			long time = getTime(n, m, arr);
			//시간을 바탕으로 인원수를 구하고
			int people = m;
			for(int i = 0; i < m; i++) {
				people += ((time - 1) / arr[i]);
			}
			//인원수를 바탕으로 마지막 놀이공원의 인덱스를 구할 수 있다.
			for(int i = 0; i < m; i++) {
				
				if(time % arr[i] == 0) {
					people++;
				}
				if(people == n) {
					result = i + 1;
					break;
				}
			}
		}
		System.out.println(result);
	}


}
