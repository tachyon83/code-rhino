import java.io.*;

public class Main {
	
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
    String arr[] = br.readLine().split(" ");
		int N = Integer.parseInt(arr[0]);
		int K = Integer.parseInt(arr[1]);
		
		String tmprt[] = br.readLine().split(" ");
		int hap = 0;
		for (int i = 0; i < K; i++) {
			hap += Integer.parseInt(tmprt[i]);
		}
		int max = hap;
		
		for (int i = K; i < N; i++) {
			hap -= Integer.parseInt(tmprt[i - K]);
			hap += Integer.parseInt(tmprt[i]);
			if (max < hap) {
                max = hap;
            } else {
                max = max;
            }
		}
		bw.write(String.valueOf(max));
		bw.flush();
	}
}
