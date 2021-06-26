import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
 
public class Main {
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int L = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
 
        int N = Integer.parseInt(br.readLine());
 
        int[] cube = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int f = Integer.parseInt(st.nextToken());
 
            cube[t] = f;
        }
 
        long before = 0; // 이전에 사용된 큐브의 개수
        long ans = 0;
        for (int i = N - 1; i >= 0; i--) { // 반복문을 돌 때마다, 박스를 2^i x 2^i x 2^i로 분할해서 생각한다.
            // 현재 박스는 before보다 분할을 1번 더 시행했으므로 before의 개수를 2^3만큼 늘려주어야 한다.
            // 예를 들어, 4 x 4 x 4 분할 단계에서 before = 1이었다고 하자.
            // 그러면, 현재는 2 x 2 x 2 분할이 되므로 before = 8이 된다.
            before <<= 3;
 
            // 박스를 2^i x 2^i x 2^i만큼 분할해 주고, 전에 박스를 채웠던 큐브의 개수(before)만큼 빼 준다.
            // 만약, 분할이 불가능하다면 0이 나올 것이다.
            long possibleCube = (long) (L >> i) * (W >> i) * (H >> i) - before;
            long newCube = Math.min((long) cube[i], possibleCube); // 새롭게 박스에 추가된 큐브
 
            before += newCube; // 새롭게 추가된 큐브는 다음 반복문에서 과거가 되므로 before에 추가해 준다.
            ans += newCube;
        }
 
        if (before == (long) L * W * H) { // 위에서 계산한 before가 실제 박스의 부피와 같아야 함.
            bw.write(ans + "\n");
        } else { // 같지 않으면, 주어진 큐브로는 박스를 구성할 수 없다.
            bw.write("-1\n");
        }
 
        bw.flush();
        bw.close();
        br.close();
    }
 
}
