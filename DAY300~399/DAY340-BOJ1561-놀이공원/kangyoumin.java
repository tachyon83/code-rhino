package binarySearch;
import java.io.*;
import java.util.*;

public class Main {
	static int maxM;
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		long n = Long.valueOf(st.nextToken());	// 전체 명 수  
		int m = Integer.valueOf(st.nextToken());// 전체 놀이기구 수 
		
		int[] ridesTime = new int[m];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) {
			ridesTime[i] = Integer.valueOf(st.nextToken());
			maxM = Math.max(maxM, ridesTime[i]);
		}
		
		long result = binarySearch(ridesTime, n, m);
		
		// result - 1 분일 때 총 인원 수 구하기 
		long prevTime = result - 1;
		long prevCount = m;	
		long[] prevRidesTime = new long[m];
		for(int i = 0; i < m ; i++) {
			prevRidesTime[i] = prevTime / ridesTime[i];
			prevCount += prevRidesTime[i];
		}
		
		// 마지막 학생이 타는 놀이기구 찾기
		long nowNeedsCount = n - prevCount;
		long nowCount = 0;
		long ridesNum = n;	
		for(int i = 0; i < m; i++) {
			if(result / ridesTime[i] != prevRidesTime[i]) {
				nowCount++;
				if(nowCount == nowNeedsCount) {
					ridesNum = i + 1;	
					break;
				}
			}
		}
		
		System.out.println(ridesNum);
	}
	
	static public long binarySearch(int[] ridesTime, long n, int m) {
		long left = 0;
		long right = (n / m) * maxM;	// 최대 나올 수 있는 시간 
		long result = 0;
		
		while(left <= right) {
			long mid = (left + right) / 2; 
			long count = m;
			for(int i = 0; i < m ; i++) {
				count += mid / ridesTime[i];
			}
			if(n <= count) {
				result = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return result;
	}
}
