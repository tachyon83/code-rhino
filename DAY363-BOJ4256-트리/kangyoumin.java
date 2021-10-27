public class Main {
    
    static int pre[];
    static int in[];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while(t-->0) {
            int n = sc.nextInt();
            pre = new int[n+1];
            in = new int[n+1];
            for(int i=0; i<n; i++)
                pre[i] = sc.nextInt();
            for(int i=0; i<n; i++)
                in[i] = sc.nextInt();
            
            postorder(0, n, 0);
            System.out.println();
        }
    }
    
    public static void postorder(int s, int e, int r) {
        for(int i=s; i<e; i++) {
            if(in[i] == pre[r]) {
                postorder(s, i, r+1);
                postorder(i+1, e, r+i-s+1);
                System.out.print(pre[r] + " ");
            }
        }
    }
}
