
import java.io.*;
import java.util.*;



public class Main{
	static int N;
	static int M;
	
	static boolean isStringDouble(String s) {
		try {
			Double.parseDouble(s);
			return true;
		}catch(NumberFormatException e) {
			return false;
		}
	}
	/*
	 * Double.parseDouble()은 문자열을 실수로 변환해서, 에러가 나면 숫자로 아닌 것을 판단하여 false를 반환
	 * 10진수 숫자여부만 판단가능
	 */

	public static void main(String [] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s[] = bf.readLine().split(" ");
		N = Integer.parseInt(s[0]); //도감에 수록된 포켓몬 개수
		M = Integer.parseInt(s[1]); //내가 맞춰야 하는 개수
		
		HashMap<String, Integer> map = new HashMap<String, Integer>(N);
		HashMap<Integer,String> map2 = new HashMap<Integer, String>(N);
		
		
		for(int i=1;i<=N;i++) {
			String word = bf.readLine();
			map.put(word, i);
			map2.put(i, word);
			
		}
		
		
		for(int j=1;j<=M;j++) {
			String word2 = bf.readLine();
			if(isStringDouble(word2)) { // 숫자
				Integer word = Integer.parseInt(word2);
				String answer_1 = map2.get(word);
				System.out.println(answer_1);
			}
			else { //숫자 아님
				Integer answer_2 = map.get(word2);
				System.out.println(answer_2);
			}
		}
		
		
		
		
	}

}
