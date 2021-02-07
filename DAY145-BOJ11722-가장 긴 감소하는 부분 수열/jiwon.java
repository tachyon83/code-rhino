//실패

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		//Stack<String> stack = new Stack<String>();

		int n = Integer.parseInt(bf.readLine());
		
		
		int input[] = new int[n];
		
		String s[] = bf.readLine().split(" ");
		for(int i=0;i<n;i++) {
			input[i] = Integer.parseInt(s[i]);
		}

		
		int res = 1;
		for (int i = 1; i < n; i++) {
			if(input[i-1] > input[i]) {
				res++;
			}else {
				
			}
		}
		if(n!=1)
			System.out.println(res);
		else
			System.out.println(1);

	}

}
