//미완성


import java.io.*;
import java.util.*;

class Solution {
	public int solution(String name) {
		int cursor = 0; // 다 만든 글자수
		double success = 0.0;
		String[] s = name.split("");
		int answer = 0;
		int rest = s.length;
		int[] complete = new int[s.length];

		for (int i = 0; i < s.length; i++) {
			if (s[i].equals("A")) {
				complete[i] = 1; // 만들 문자가 'A'이면 넘어가기
				success += 1.0;
				rest--;
			}
		}

		HashMap<String, Integer> ud = new HashMap<String, Integer>();
		ud.put("A", 0);
		ud.put("B", 1);
		ud.put("C", 2);
		ud.put("D", 3);
		ud.put("E", 4);
		ud.put("F", 5);
		ud.put("G", 6);
		ud.put("H", 7);
		ud.put("I", 8);
		ud.put("J", 9);
		ud.put("K", 10);
		ud.put("L", 11);
		ud.put("M", 12);
		ud.put("N", 13);
		ud.put("O", 12);
		ud.put("P", 11);
		ud.put("Q", 10);
		ud.put("R", 9);
		ud.put("S", 8);
		ud.put("T", 7);
		ud.put("U", 6);
		ud.put("V", 5);
		ud.put("W", 4);
		ud.put("X", 3);
		ud.put("Y", 2);
		ud.put("Z", 1);

		int back_pass = s.length;
		int back = 0; // 1이되면 맨 뒤로 커서 이동

		for (String s2 : s) {
			System.out.println(s2 + " ");
		}

		System.out.println(ud.get((s[cursor])));

		while (rest > 0) {
			System.out.println("\ncursor : " + cursor + "; answer : " + answer + "; rest : " + rest);

			if (cursor < 0 || cursor >= s.length || success >= s.length) {
				break;
			}

			// (현재 위치(=cursor)가 50퍼 미만이고 && 완성 시킨게 50퍼 넘으면) 커서 뒤로가기
			if (cursor < success && success > s.length / 2) {
				System.out.println("====" + 1 + "====");
				answer += cursor;
				back = 1;
				cursor = s.length - 1;
				System.out.println("요기서 while문 다시 시작");
				continue;
			}

			if (complete[cursor] == 1) {
				if (back == 0)
					cursor++;
				else
					cursor--;
				System.out.println("요기서 while문 다시 시작2");
				continue;

			}

			else if (back == 0) {
				System.out.println("====" + 2 + "====");
				if (complete[cursor] == 1) {
					cursor++;
					continue;
				}
				System.out.println(ud.get(s[cursor]));
				answer += ud.get(s[cursor]);
				success += 1.0;
				complete[cursor] = 1;
				cursor++;
				if (cursor < s.length) {
					answer++;
					System.out.println("answer 1 증가2222");
				}
				if (cursor == s.length - 1) {
					break;
				} 
			}

			else if (back == 1) {
				System.out.println("====" + 3 + "====");
				answer += ud.get(s[cursor]);
				System.out.println(ud.get(s[cursor]));
				success += 1.0;
				complete[cursor] = 1;
				cursor--;
				if (cursor < s.length) {
					answer++;
					System.out.println("answer 1 증가3333");
				}
				if (cursor == s.length) {
					break;
				}

			}

			

		}

		return answer;
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		// BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		// StringBuilder sb = new StringBuilder();

		String name = "JAN";
		Solution sol = new Solution();
		int result = sol.solution(name);

		System.out.println(result);

		// String s2[] = bf.readLine().split(" ");
		// int n = Integer.parseInt(s2[0]);
		// int s = Integer.parseInt(s2[1]);

	}

}
