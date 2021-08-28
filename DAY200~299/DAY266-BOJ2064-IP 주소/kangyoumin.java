import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int[] ip;
	static int n, networkIp = 0, networkMask = 0;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		ip = new int[n];
		for(int i = 0; i < n; i++) {
			String s = br.readLine();
//			.은 메타 문자이므로 "."->X "\\."또는 "[.]"이런식으로 표현하기
			String[] temp = s.split("[.]");
			s = "";
			int thisNum = 0;
			int k = 3;
			for(int j = 0; j < 4; j++, k--) {
				thisNum |= Integer.parseInt(temp[j]) << (8*k);
			}
			ip[i] = thisNum;
		}
		
		a:
		for(int i = 31; i >= 0; i--) {
			int bit = 1 << i;
			for(int j = 1; j < n; j++) {
//				ip[] 에 있는 것을 인덱스마다 하나씩 비교
				int one = ip[j-1];
				int next = ip[j];
//				다른것이 있다면 이중포문 밖으로 나가기
				if((one & bit) != (next & bit)) break a;
			}
//			다른 것이 없다면 계속 1추가
			networkMask |= bit;
		}
		
		int shift = 24;
		for (int i = 0; i < 4; i++, shift -= 8) {
//			오른쪽 시프트 이용
//			networkIp는 어떤 주소든 상관없이 ip주소 & networkMask 해주면 된다
			System.out.print(((ip[0] & networkMask) >> shift) & (1 << 8) - 1);
//			맨마지막에는 .을 안붙인다
		    if (i != 3) System.out.print('.');
		}
		System.out.print('\n');
		
		for (int i = 0; i < 4; i++, shift -= 8) {
			System.out.print((networkMask >> shift) & (1 << 8) - 1);
		    if (i != 3) System.out.print('.');
		}
		
	}

}
