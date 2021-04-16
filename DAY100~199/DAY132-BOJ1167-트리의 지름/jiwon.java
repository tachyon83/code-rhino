//데이터 입력까지 완료 dfs 부분 추가해야함...


import java.io.*;
import java.util.*;



public class Main{
	static int N;
	static int array[][];
	static boolean block[][];
	
	static void showArray() {
		for(int i=0;i<N;i++) {
			System.out.print(i+" : ");
			for(int j=0;j<100;j++) {
				if(array[i][j] == 0) {
					break;
				}else {
					System.out.print(array[i][j]+" ");
				}
			}System.out.println();
		}
	}
	
	static int startDFS(int s, int max) {
		for(int i=0;i<N;i++) {
			int startNode = array[i][0];
			for(int j=1;j<100000;j+=2) {
				if(array[i][j]==0) {
					return max;
				}else {
					max =+ array[i][j];
					if(block[i][j] == false) {
						startDFS(array[i][j],max);
					}
					
				}
			}
			
		}
		return -1;
	}
	
	public static void main(String [] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		array = new int[N][100000];
		for(int i=0;i<N;i++) {
			String s[] = bf.readLine().split(" ");
			for(int j=0;j<s.length-1;j++) {
				if(s[j].contentEquals("-1")) {
					
				}
				else {
					array[i][j] = Integer.parseInt(s[j]);
				}
			}
		}
		
		showArray();
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i=0;i<N;i++) {
			for(int j=1;j<100000;j+=2) {
				if(array[i][j]==0) {
					break;
				}
				else {
					int key = array[i][0] * 10 + array[i][j];
					int value = array[i][j+1];
					map.put(key, value);
				}
			}
		}
		
		
		// 값 전처리 완료
		
		
		//dfs 시작
		
		int diameter = 0;
		
		block = new boolean[N][100000];
		
		
		
	}

}
