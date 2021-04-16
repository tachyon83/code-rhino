import java.util.Arrays;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 1;

		Arrays.sort(people);
		int sum = 0;
		for (int front = 0, rear = people.length - 1; front <= rear;) {
			if (sum + people[rear] > limit) {
				if (sum + people[front] > limit) {
					sum = 0;
					answer++;
				} else {
					sum += people[front];
					front++;
				}
			} else {
				sum += people[rear];
				rear--;
			}
		}

		return answer;
    }
}