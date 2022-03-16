import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;
import java.util.StringTokenizer;


class Main{
    public static char[][] map;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        int r=Integer.parseInt(st.nextToken());
        int c=Integer.parseInt(st.nextToken());
        map=new char[r][c];
        for (int i = 0; i < r; i++) {
            s=br.readLine();
            map[i]=s.toCharArray();
        }

        int[][] d={{1,1},{0,1},{-1,1}};
        
        int ans=0;
        for (int i = 0; i < r; i++) {
            Stack<int[]> stack=new Stack<>();
            stack.push(new int[]{i,0});
            while(!stack.isEmpty()){
                int[] temp=stack.pop();
                int x=temp[0],y=temp[1];
                map[x][y]='x';
                if(y==c-1){
                    ans++;
                    break;
                }
                for (int j = 0; j < 3; j++) {
                    int nx=x+d[j][0],ny=y+d[j][1];
                    if( 0<=nx&&nx<r && 0<=ny && ny<c && map[nx][ny]=='.'){
                        stack.push(new int[]{nx,ny});
                    }
                }
            }
        }
        System.out.println(ans);

    }

}
