
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		a:
		for(int i = 0; i < t; i++) {
			String s = br.readLine();
			int n = Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder();
			sb.append("[");
			String str = br.readLine();
//			숫자 개수가 0일때
			if(n == 0) {
				if(s.contains("D")) System.out.println("error");
				else System.out.println("[]");
				continue;
			}
//			[]지우기
			str = str.substring(1, str.length()-1);
//			push, pop, offer, poll 다 사용가능
			Deque<String> dq = new ArrayDeque<String>();
			String[] ss = str.split(",");
			for(String sss : ss) {
				dq.offer(sss);
			}
			
//			홀수면 안뒤집힘 짝수면 뒤집힘 
			int check = 1;
			for(char ch : s.toCharArray()) {
				if(ch == 'R') {
					check ++;
				}else {
					if(dq.isEmpty()) {
						System.out.println("error");
						continue a;
					}
					if(check % 2 == 0){
						dq.pollLast();
					}else {
						dq.pollFirst();
					}
				}
			}
			
//			남아있는 게 없는 경우 -> RDD 2 [1,2]
			if(dq.isEmpty()) {
				System.out.println("[]");
				continue;
			}
			while(!dq.isEmpty()) {
				if(check % 2 == 0) {
					sb.append(dq.pollLast()+",");
				}else {
					sb.append(dq.pollFirst()+",");
				}
			}
//			마지막 ,지우기
			sb.deleteCharAt(sb.length()-1);
			sb.append("]");
			System.out.println(sb);
		}
	}

}
