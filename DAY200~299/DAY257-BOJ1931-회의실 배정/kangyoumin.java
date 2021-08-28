import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		time[] times = new time[n];
		int end = -1;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			times[i] = new time(s, e);
		}
		
//		종료 시간에 맞게 정렬
//		만약 종료시간이 같다면 시작시간에 맞게 정렬 
		Arrays.sort(times);
		
//		시작시간>=이전 times의 끝난시간 이면 cnt++
		for(int i = 0; i < n; i++) {
			if(times[i].start >= end) {
				end = times[i].end;
				cnt++;
			}
		}
		
		System.out.println(cnt);

	}

}
class time implements Comparable<time>{
	int start;
	int end;
	
	public time (int start, int end) {
		this.start = start;
		this.end = end;
		
	}

	@Override
	public int compareTo(time t) {
		if(t.end == this.end) {
			return Integer.compare(this.start, t.start);
		}else {
			return Integer.compare(this.end, t.end);
		}
		
	}
	
}
