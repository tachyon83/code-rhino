
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int N, K;
	static int[] arr;
	static boolean[] checkused;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new int[K];
//		콘센트가 꽂혔는지 tf
		checkused = new boolean[101];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < K; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
//		총 몇개의 플러그가 꽂혀 있는지
		int usedPlug = 0;
//		몇번 뺏다가 끼는지
		int cnt = 0;
		for(int i = 0 ; i < K; i++) {
			int key = arr[i];
//			콘센트가 꽂혀있지 않은 경우
			if(!checkused[key]) {
//				콘센트에 꽂을 공간이 있는 경우
				if(usedPlug != N) {
					checkused[key] = true;
					usedPlug++;
				}else {
					ArrayList<Integer> list = new ArrayList<Integer>();
//					현재 꽂혀있는 콘센트가 나중에도 사용되는지 (콘센트 사용순서대로 확인해줘야 한다)
					for(int j = i; j < K; j++) {
						if(checkused[arr[j]] && !list.contains(arr[j])) {
							list.add(arr[j]);
						}
					}
//					나중에 사용되지 않는 콘센트가 있을 때
					if(list.size() != N) {
						for(int j = 0; j < checkused.length; j++) {
//							해당 콘센트를 뽑아주기
							if(checkused[j] && !list.contains(j)) {
								checkused[j] = false;
							}
						
						}
//						나중에 둘다 사용될 때
					}else {
//						!더 늦게 사용할 콘센트를 뽑아주기(나중에 어차피 뽑게 되므로)
						int remove = list.get(list.size()-1);
						checkused[remove] = false;
					}
	
					checkused[key] = true;
					cnt++;
				}
		
			}
			
		}System.out.println(cnt);
	}

}
