//메모리 초과.... 다시 ...
import java.io.*;
import java.util.*;



public class Main{
	static int [][] number;
	static int [][] count;
	static int [][] partsum;
	static int N; 

	
	static void showA() {
		System.out.println();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				System.out.print(number[i][j]+" ");
			}System.out.println();
		}
	}
	
	static void showB() {
		System.out.println();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				System.out.print("["+ (N*(i-1)+ j) +"]"+ count[(N*(i-1)+ j)][1] +"  ");
			}System.out.println();
		}
	}
	static void showC() {
		System.out.println();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				System.out.print("["+ (N*(i-1)+ j) +"]"+ partsum[(N*(i-1)+ j)][1] +"  ");
			}System.out.println();
		}
	}
	
	static int find(int s, int e, int find) {
		for(int i=s;i<=e;i++) {
			int A = partsum[i-1][1];
			int B = partsum[i][1];
			if(A <= find && find <= B) {
				return i;
			}else if(A >= find){	
				return find(s,(s+e)/2,find);
			}else {
				return find((s+e)/2+1, e, find);
			}
		}
		return 1;
	}

	public static void main(String [] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		int K = Integer.parseInt(bf.readLine());

		number = new int[N+1][N+1];
		count = new int[N*N+1][2];
		partsum = new int[N*N+1][2];


		for(int i=1;i<=N;i++) {
			for(int j=1; j<=N;j++) {
				number[i][j] = i*j;
			}
		}

		for(int i=1;i<=N*N/2;i++) {
			count[i][0] = i;
		}
		
		int stop=0;
		int break2=0;
		
		for(int i=1;i<=N;i++) {
			if(break2 == 1) { break; }
			for(int j=1;j<=N;j++) {
				int num = number[i][j];
				count[num][1]++;	
				stop++;
			}//for
		}//for


		int result=0;
		
		int max = 0; int value = 0;
		for(int i=0;i<N*N/2;i++) {
			if(value < count[i][1] && max > i) {
				max = i;
				value = count[i][1];
			}
		}
		
		showA();
		showB();
		showC();
		
		int sum=0;
		for(int i=1;i<=N*N;i++) {
			partsum[i][1] = count[i][1] + partsum[i-1][1];
			sum+=partsum[i-1][1];
		}
		
		int s=0; int e=N; int res=0;
		while(true) {
			if(s>e || s==e) {
				break;
			}else {
				res = find(s,e,K);
				if(res == K) {
					break;
				}
			}
		}
		result = res;
		System.out.println(result);

	}




}

