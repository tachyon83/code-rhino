import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int cnt;
	static boolean S[] = new boolean[20];
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		cnt = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < cnt; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String ops = st.nextToken();
			String op = ops.substring(0, 2);
			if(op.equals("al"))
				Arrays.fill(S, true);
			else if(op.equals("em"))
				Arrays.fill(S, false);
			else {
				int num = Integer.parseInt(st.nextToken());
				oper(op, num);
			}
		}
		System.out.println(sb);

	}
	
	public static void oper (String op, int n) {
		switch (op) {
		case "ad":
			S[n-1] = true;
			break;
		case "re":
			S[n-1] = false;
			break;
		case "ch":
			if(S[n-1])
				sb.append(1+"\n");
			else
				sb.append(0+"\n");
			break;
		default:
			if(S[n-1])
				S[n-1] = false;
			else
				S[n-1] = true;
			break;
		}
	}
}
