import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	
	public static void main(String[] args) throws Exception{
		
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int h = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		int[] arr = new int[w];
		st = new StringTokenizer(input.readLine());
		for(int i = 0; i < w; i++) arr[i] = Integer.parseInt(st.nextToken());
		int answer = 0;
		
		for(int i = 1; i < w - 1; i++) {
			
			int currentHeight = arr[i];
			int leftHeight = currentHeight;
			int rightHeight = currentHeight;
			int height = 0;
			
			//왼쪽 검사
			for(int j = i - 1; j >= 0; j--) {
				height = arr[j];
				leftHeight = Math.max(leftHeight, height);
			}
			
			//오른쪽 검사
			for(int j = i + 1; j < w; j++) {
				height = arr[j];
				rightHeight = Math.max(rightHeight, height);
			}
			
			//leftHeight와 rightHeight 중 min값이 currentHeight보다 크다면  answer 최신화
			height = Math.min(leftHeight, rightHeight);
			if( height > currentHeight) {
				answer += (height - currentHeight);
			}
		}
		
		System.out.println(answer);
	}

}
