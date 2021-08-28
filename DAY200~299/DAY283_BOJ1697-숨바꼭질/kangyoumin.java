import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, k, length;
	static int[] visit = new int[100001];

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		if (n == k) {
            System.out.println(0);
        } else {
            bfs(n);
        }
	}
	
	public static void bfs (int x) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(x);
		visit[x] = 1;
		
		while(!q.isEmpty()) {
			int tempX = q.poll();
			
			for(int i = 0; i < 3; i++) {
				
				int _x = oper(i, tempX);
//				System.out.println(_x);

				if(_x == k) {
					System.out.println(visit[tempX]);
					return;
				}
				//if(visit[_x] != 0 || _x < 0 || _x > 100000) continue;
				//q.add(_x);
				//visit[_x] = visit[tempX] + 1;
				
				if (_x >= 0 && _x <= 100000 && visit[_x] == 0) {
                    q.add(_x);
                    visit[_x] = visit[tempX] + 1;
                }
				
			}
		}
	}
	
	public static int oper (int op, int x) {
		if(op == 0) {
			return x-1;
		}else if(op == 1) {
			return x+1;
		}else {
			return 2*x;
		}
		
	}

}
