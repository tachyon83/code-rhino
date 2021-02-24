package silver1.B1148;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		List<String> dictionary = new ArrayList<>();
		String word = br.readLine();
		while (!"-".equals(word)) {
			dictionary.add(word);
			word = br.readLine();
		}

		int[][] alphabets = new int[dictionary.size()][26];

		for (int i = 0; i < dictionary.size(); i++) {
			char[] data = dictionary.get(i).toCharArray();
			for (char c : data) {
				alphabets[i][c - 'A']++;
			}
		}

		word = br.readLine();
		
		List<Character> maxList, minList;
		StringBuilder sb = new StringBuilder();

		while (!"#".equals(word)) {
			int min = Integer.MAX_VALUE, max = -1;
			
			maxList = new ArrayList<>();
			minList = new ArrayList<>();
			
			int[] count = new int[26];	// 맵에 있는 스펠링
			char[] data = word.toCharArray();
			for(char c : data) {
				count[c-'A']++;
			}
			
			for(int i=0;i<26;i++) {
				if(count[i]>0) {
					for(int j=0;j<alphabets.length;j++) {
						
					}
				}
			}
		}

	}

}
