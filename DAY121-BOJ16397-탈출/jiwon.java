
//푸는중
import java.io.*;
import java.util.*;

public class Main{
	
	static int N; //LED로 표현된 수
	static int T; //버튼을 누를 수 있는 최대 횟수
	static int G; //탈출을 위해 똑같이 만들어야 하는 수
	static int visited[];
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
		int next = number;
		next++;
		if(next > 99999) 
			return 0;
		else 
			return next;
	}

	public static int Bbutton(int number) {
		int next = number;
		//System.out.println(number);
		next = next * 2;
		if(next > 99999) 
			return 0;
		int count = 0;
		while(next >= 10) {
			next /= 10;
			count ++;
		}
		
		next = number - ((1) * (int)Math.pow(10.0, count));
	
		
		//System.out.println(next);
		return next;
	}

	public static int bfs() {
		Queue<Pair> q = new LinkedList();
		int count = 1;
		q.offer(new Pair(N, 0));
		System.out.println("offer1 : "+q.peek().number+" "+q.peek().time);
		visited[N]=1;
		int cur = G;
		while(!q.isEmpty()) {
			Pair now = q.poll();
			if(q.peek()!=null)	
				System.out.println("poll : "+q.peek().number+" "+q.peek().time);
			if(now.number == G) {
				return now.time;
			}
			else if(now.time > T) {
				return 0;
			
			}
			
			int result = Abutton(now.number);
			
			if(result != 0) {
				q.offer(new Pair(result, count++));
				System.out.println("offer2 : "+q.peek().number+" "+q.peek().time);
				visited[cur] = 1;
			}
			
			if(now.number == 0) {
				continue;
			}
			
			result = Bbutton(cur);
			if(result != 0) {
				int next = result;
				if(visited[next] == 0) {
					visited[next] = 1;
					q.offer(new Pair(next, count++));
					System.out.println("offer3 : "+q.peek().number+" "+q.peek().time);
				}
			}
			
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
		
		visited = new int[G+1];

		int answer = bfs();
		if(answer == -1) {
			System.out.println("ANG");
		}else {
			System.out.println(answer);
		}
		
		
	

	}




}
