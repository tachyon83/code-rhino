class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
		String numbers = "-";
		int len = m * (t + 1);
		int index = 0;
		while (numbers.length() < len) {
			numbers += Integer.toString(index, n).toUpperCase();
			index++;
		}
		for (int i = 0; i < t; i++) {
			answer += numbers.charAt(i * m + p);
		}
		return answer;
    }
}