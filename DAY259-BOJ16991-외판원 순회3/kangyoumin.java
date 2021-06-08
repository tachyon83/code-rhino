//시간초과..

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] arr;
//	dp[현재 도시 위치][방문조합을 비트 마스크]
	static double[][] dp;
	static int MAX = 100000;
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][2];
		dp = new double[N][(1<<N)];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
//			x좌표
			arr[i][0] = Integer.parseInt(st.nextToken());
//			y좌표
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
//		MAX로 초기화
		for(int i = 0; i < N; i ++) {
			Arrays.fill(dp[i], MAX);
		}
		
//		0번 도시에서 시작 하는 이유 => 어차피 출발지점으로 돌아가야하고 한붓그리기, 
//		따라서 어디에서 출발하든 같은 최소값이 나온다. TSP(0, (1<<0))
		double answer = Math.round(TSP(0,1) * 1000000)/1000000.0;
		System.out.println(answer);
	}
	
//	현재도시, 지금까지 방문했던 도시(비트마스킹)
	static double TSP (int current, int visited) {
		double here = dp[current][visited];

//		모든 도시를 다 방문 했을 경우 here에 처음위치(0)까지의 거리를 넣어주면 된다.
		if(visited == ((1<<N)-1)) return here = dist(current, 0);

//		here가 MAX가 아니라는 것은 이미 한번 왔던 것. 
//		=> 굳이 한번 더 구할 필요X 값을 그대로 가져다 쓰기
		if(here != MAX) return here;
		
		
		for(int i = 0; i < N; i++) {
//			현재 방문한 도시들 | i번째 방문할 도시
			int next = visited | (1<<i);

//			지금까지 방문했던 도시 중에 있다면 
			if((visited & (1<<i)) != 0) continue;

//			Top-down 방식.(결국에는 [0][1]에 들어있는 게 답) 
//			ex) 0->1 과 0->2(0->1->2) 중에 작은것
			here = Math.min(here, TSP(i, next) + dist(i, current));
		}
		
		return here;
	}
	
//	거리구하는 함수
	static double dist (int a, int b) {
		int dx = arr[a][0] - arr[b][0];
		int dy = arr[a][1] - arr[b][1];
		return Math.sqrt((dx * dx) + (dy * dy));
	}

}
