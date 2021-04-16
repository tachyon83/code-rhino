
import java.io.*;
import java.util.*;

public class Main{

	static int N; //LED로 표현된 수
	static int T; //버튼을 누를 수 있는 최대 횟수
	static int G; //탈출을 위해 똑같이 만들어야 하는 수
	static int visit[];
	int count;



	static class Pair{
		int number;
		int time;
		Pair(int number, int time){
			this.number = number;
			this.time = time;
		}
	}

	public static int Abutton (int number) {

		if((number+1) > 99999) 
			return 0;
		else 
			return number+1;
	}

	public static int Bbutton(int number) {
		int next = number * 2;
		
		if(next > 99999) 
			return 0;
		int count = 0;
		if(next < 10) {
			next--;
		}
		else {
			while(next >= 10) {
				next /= 10;	//twice = 1 1
				count ++; 	//count = 1;
			}
			next = (number*2) - ((1) * (int)Math.pow(10.0, (double)count));
		}
		

		return next;
	}
	
	

	public static int bfs() {
		
		Queue<Pair> q = new LinkedList<>();
		q.offer(new Pair(N, 0));
		
		visit[N]=1;
		
		while(!q.isEmpty()) {
			
			//deep++;
			Pair now = q.poll();
			
			int number = now.number;
			
			if(now.time > T) { return -1; }
			
			else if(now.number == G) { return now.time; }

			
			
			//Abutton
			int result = Abutton(number);	//number = 1
			if(result != 0 && visit[result] == 0) {
				q.offer(new Pair(result,now.time+1));
				visit[result] = 1;

			}


			if(now.number == 0) {
				continue;
			}


			//Bbutton
			result = Bbutton(number);
			if(result != 0 && visit[result] == 0) {
				visit[result] = 1;
				q.offer(new Pair(result,now.time+1));
			}/*
			
			for(Pair pp : q) {
				System.out.print("("+pp.number + " "+pp.time+")");
			}System.out.println();
			
			System.out.println("\n");
			*/
		
			
		}




		return -1;

	}

	public static void main(String [] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Queue<Pair> q = new LinkedList<Pair>();

		String s[] = bf.readLine().split(" ");

		N = Integer.parseInt(s[0]);
		T = Integer.parseInt(s[1]);
		G = Integer.parseInt(s[2]);

		visit = new int[100000];

		int answer = bfs();
		if(answer == -1 ) {
			System.out.println("ANG");
		}else {
			System.out.println(answer);
		}




	}




}
