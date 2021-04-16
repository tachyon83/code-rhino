import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		char[][] gear = new char[4][8];
		int[] cur = { 0, 0, 0, 0 };
		int[] next = { 0, 0, 0, 0 };

		for (int i = 0; i < 4; i++) {
			gear[i] = br.readLine().toCharArray();
		}

		int K = Integer.parseInt(br.readLine());
		for (int k = 0; k < K; k++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int gearNum = Integer.parseInt(st.nextToken()) - 1;
			int direction = Integer.parseInt(st.nextToken());
			int d = direction == 1 ? -1 : 1;
			int temp = cur[gearNum] + d;
			next[gearNum] = (temp < 0) ? temp + 8 : ((temp > 7) ? temp - 8 : temp);
			d *= -1;

			for (int i = gearNum + 1; i < 4; i++) { // 오른쪽 톱니
				// 1. i-1의 2번 톱니랑 i의 6번 톱니 확인 : 같으면 브레이크
				if (gear[i - 1][(cur[i - 1] + 2) % 8] == gear[i][(cur[i] + 6) % 8]) {
					break;
				}
				// : 다르면 돌려야돼
				temp = cur[i] + d;
				next[i] = (temp < 0) ? temp + 8 : ((temp > 7) ? temp - 8 : temp);
				d *= -1;
			}
			d = direction;
			if (next[gearNum] != cur[gearNum]) {
				for (int i = gearNum - 1; i >= 0; i--) { // 왼쪽 톱니
					// i의 2번 톱니랑 i+1의 6번 톱니 확인
					if (gear[i][(cur[i] + 2) % 8] == gear[i + 1][(cur[i + 1] + 6) % 8]) {
						break;
					}
					temp = cur[i] + d;
					next[i] = (temp < 0) ? temp + 8 : ((temp > 7) ? temp - 8 : temp);
					d *= -1;
				}
			}
			for (int i = 0; i < 4; i++) {
				cur[i] = next[i];
			}

//			for(int i=0;i<gear.length;i++) {
//				System.out.print(cur[i]+" ");
//			}
//			System.out.println();
		}
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += gear[i][cur[i]] == '1' ? Math.pow(2, i) : 0;
		}

		System.out.println(sum);

	}

}
