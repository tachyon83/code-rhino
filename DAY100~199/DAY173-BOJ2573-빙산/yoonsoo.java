public class Main {
	
	
	static int sea[][];
	static boolean visited[][];
	static int a[];
	static int b[];
	static int count;
	static int arr[][];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		a = new int[]{1,-1,0,0};
		b = new int[]{0,0,1,-1};
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		sea = new int[n][m];


		for(int i = 0; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				sea[i][j] = sc.nextInt();
			}
		}
		int tryy = 0;
		while(true) {
			count = 0;
			arr = new int[n][m];
			visited = new boolean[n][m];
			for(int i = 0; i < n ; i++) {
				for(int j = 0 ; j < m ; j++) {
					if(visited[i][j] == false && sea[i][j] >0) {
						visited[i][j] = true;
						dfs(i,j,n,m);
						count++;
//						System.out.println(count);
					}
				}
			}
			for(int i = 0; i < n ; i++) {
				for(int j = 0 ; j < m ; j++) {
					sea[i][j] = sea[i][j] - arr[i][j] >0 ? sea[i][j] - arr[i][j] : 0;
//					System.out.print(sea[i][j]+" ");
				}
//				System.out.println();
			}
			if(count >1)break;
			tryy ++;
		
			if(allmelt(n,m)) {
				tryy = 0; 
				break;
			}
		}
		
		
		System.out.println(tryy);
		
	}
	
	
	
	public static void dfs(int x, int y,int n,int m) {
		int zero = zerocount(x,y,n,m);
		arr[x][y] =zero ;
		
		for(int i = 0 ; i < 4 ; i++) {
			int aroundx = x+a[i];
			int aroundy = y+b[i];
			if(aroundx >= 0 &&aroundy >= 0 && aroundx <n && aroundy <m) {
				if(sea[aroundx][aroundy]>0&& visited[aroundx][aroundy] == false) {
					visited[aroundx][aroundy] =true;
					dfs(aroundx,aroundy,n,m);
				}
			}
			
		}
	}
	
	public static int zerocount(int x, int y,int n,int m) {
		int count = 0;
		
		for(int i = 0 ; i < 4 ; i++) {
			int aroundx = x+a[i];
			int aroundy = y+b[i];
			if(aroundx >= 0 &&aroundy >= 0 && aroundx <n && aroundy <m) {
				if(sea[aroundx][aroundy] == 0) {
					count++;
				}
			}
			
		}
		
		return count;
		
	}
	
	
	public static boolean allmelt(int n, int m) {
		for(int i = 0; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				if(sea[i][j] !=0) {
					return false;
				}

			}
		}
		
		return true;
	}
	
	
}
