
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
//		boolean배열과 비슷 -> 메모리 훨씬 작음 byte->bit
		BitSet b = new BitSet();
//		StringTokenizer의 값이 없을 때 까지
		while(st.hasMoreTokens()) {
			int temp = Integer.parseInt(st.nextToken());
//			temp 값이 true(중복시)
			if(b.get(temp)) continue;
//			중복 아닐 때 true로 넣어주기
			b.set(temp);
			sb.append(temp + " ");
		}
		System.out.println(sb);
	}

}
