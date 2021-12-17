import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
//        시간
        int time = 0;
//        하나의 작업이 끝나는 시간
        int endtime = 0;
//        수행한 작업 개수
        int count = 0;
//        오른차순(요청시간 기준)
        Arrays.sort(jobs, (o1, o2) -> o1[0] - o2[0]);
//       힙으로 정렬 오름차순(작업량 기준)
        PriorityQueue<int[]> q = new PriorityQueue<int[]>((o1, o2) -> o1[1] - o2[1]);
        
        while(count < jobs.length) {
//        	하나의 작업이 끝나는 시점까지의 작업을 q에 넣는다
        	while (time < jobs.length && jobs[time][0] <= endtime) q.add(jobs[time++]);
//        	더이상 q에 아무것도 없다면 조금 뒤(작업이 안겹침)에 있는 것
        	if (q.isEmpty()) endtime = jobs[time][0];
//        	작업이 끝나기 전에 들어온 것중에 작업량이 젤 짧은 요청부터
        	else {
        		int[] temp = q.poll();
        		answer += temp[1] + endtime - temp[0];
        		endtime += temp[1];
        		count++;
        	}
        	
        }
//        소수점 버림
        return (int) Math.floor(answer/jobs.length);
    }
}
