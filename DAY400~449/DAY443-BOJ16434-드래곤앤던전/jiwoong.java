import java.io.*;
import java.util.*;



public class jiwoong{
    static int n;
    static int[][] map;
    public static void main(String []args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        int dmg = Integer.parseInt(st.nextToken());
        int hp = 0;
        map = new int[n][3];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());

            map[i][0] = Integer.parseInt(st.nextToken());
            map[i][1] = Integer.parseInt(st.nextToken());
            map[i][2] = Integer.parseInt(st.nextToken());
        }
        long left = 0, right = (long)2<<62-1;
        long answer = right;
        while(left <=right){
            long mid = (left+right)>>1;
            if(isVal(mid,dmg)){
                answer = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        bw.write(answer+"\n");
        bw.flush();
        bw.close();
    }

    static boolean isVal(long hp,int dmg){
        long curHp = hp, curDmg = dmg;
        for(int i=0;i<n;i++){
            if(map[i][0] == 1){
                long count = map[i][2] / curDmg;
                if(map[i][2]% curDmg == 0) count--;
                curHp -= count *map[i][1];
                if(curHp<=0) return false;
            }else{
                curDmg += map[i][1];
                curHp = Math.min(curHp+map[i][2], hp);
            }
        }
        return true;
    }

}