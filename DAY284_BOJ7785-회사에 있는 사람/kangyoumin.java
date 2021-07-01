import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double n = Integer.parseInt(br.readLine());
		Set<String> set = new HashSet<String>();
//		리스트로 삭제시 O(n) 시간초과
		for(double i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String status = st.nextToken();
			if(status.equals("enter")) {
				set.add(name);
			}else {
				set.remove(name);
			}
		}
		ArrayList<String> list = new ArrayList<String>(set);
		Collections.sort(list, Collections.reverseOrder());
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < list.size(); i++) {
			sb.append(list.get(i)+"\n");
		}
		System.out.println(sb);
	}

}
