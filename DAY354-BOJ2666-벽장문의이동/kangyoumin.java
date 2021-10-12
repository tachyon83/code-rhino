import java.io.*;
import java.util.*;

public class Main {
    static int n,m;
    static int ans = Integer.MAX_VALUE;
    static int num[];
    public static void main(String[] args) throws  Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        String [] t = br.readLine().split(" ");        
        int open1 = Integer.parseInt(t[0]);
        int open2 = Integer.parseInt(t[1]);
        int idx = 0;        
        m = Integer.parseInt(br.readLine());
        num = new int[m];
        for(int i=0; i<m; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }
        
        dfs(open1,open2,0,0);
        System.out.println(ans);
    }
    
    public static void dfs(int open1, int open2, int level, int cnt) {
        if(level == m) {
            ans = Math.min(ans, cnt);
            return ;
        }
        int tmp_a = Math.abs(open1 - num[level]);
        int tmp_b = Math.abs(open2-num[level]);
        
        dfs(num[level],open2,level+1,cnt+tmp_a);
        dfs(open1,num[level],level+1,cnt+tmp_b);
    }
}
