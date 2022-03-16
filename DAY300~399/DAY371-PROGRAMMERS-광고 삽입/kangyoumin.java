class Solution {
    static int[] time;
	static long max = 0;
	static int maxStartIndex = 0;
	static int logsSec[][];
	
	static String solution(String play_time, String adv_time, String[] logs) {
        int playTime = toSecTime(play_time);
        time = new int[playTime+1];
        int advTime = toSecTime(adv_time);
        logsSec = new int[logs.length][2];
		toSecLog(logs);
		
		for(int i = 0; i < logs.length; i++) {
			int start = logsSec[i][0];
			int end = logsSec[i][1];
			for(int j = start; j < end; j++) {
				time[j]++;
			}
			
		}
		
		long sum = 0;
		for(int j = 0; j < advTime; j++) {
			sum += time[j];		
		}
		
        max = sum;
		for(int i = 0; i < time.length; i++) {
			if(i > (time.length-1) - advTime) break;
			sum -= time[i];
			sum += time[i+advTime];
			if(max < sum) {
				max = sum;
				maxStartIndex = i+1;
			}
		}
		
		int hour = (maxStartIndex / 60) / 60;
		int min = (maxStartIndex / 60) % 60;
		int sec = maxStartIndex % 60;
		String answer = String.format("%02d:%02d:%02d", hour, min, sec);
        return answer;
    }
	
//	time -> 초
	static int toSecTime(String time) {
		String[] temp = time.split(":");
		return Integer.parseInt(temp[0])*60*60
				+Integer.parseInt(temp[1])*60
				+Integer.parseInt(temp[2]);
	}
	
//	logs -> 초
	static void toSecLog(String[] logs) {
		for(int i = 0; i < logs.length; i++) {
			String[] temp = logs[i].split("-");
			logsSec[i][0] = toSecTime(temp[0]);
			logsSec[i][1] = toSecTime(temp[1]);
		}
	}
}
