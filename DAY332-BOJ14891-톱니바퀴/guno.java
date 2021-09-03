import java.io.*;
import java.util.*;

public class Main {

    static class Wheel{
        boolean[] isSouth = new boolean[8];

        public Wheel(String s) {
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i)=='1')
                    isSouth[i] = true;
            }
        }

        void rotate(boolean isLeft){
            if(isLeft){
                boolean temp = isSouth[0];
                for (int i = 0; i < 7; i++) {
                    isSouth[i] = isSouth[i+1];
                }
                isSouth[7]=temp;
            }else{
                boolean temp = isSouth[7];
                for (int i = 7; i > 0; i--) {
                    isSouth[i] = isSouth[i-1];
                }
                isSouth[0]=temp;

            }
        }

    }
    static final int WEST = 6;
    static final int EAST = 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        Wheel[] w = new Wheel[4];
        for (int i = 0; i < 4; i++) {
            w[i] = new Wheel(br.readLine());
        }

        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            boolean[] isRotate = new boolean[4];
            boolean[] isLeft = new boolean[4];
            isRotate[--a] = true;
            for (int j = a-1; j >=0 ; j--) {
                if(w[j].isSouth[EAST]^w[j+1].isSouth[WEST])
                    isRotate[j] = true;
                else
                    break;
            }
            for (int j = a+1; j < 4 ; j++) {
                if(w[j].isSouth[WEST]^w[j-1].isSouth[EAST])
                    isRotate[j] = true;
                else
                    break;
            }
            boolean Left = b==-1;
            isLeft[a] = Left;

            boolean temp = Left;
            for (int j = a-1; j >=0 ; j--) {
                temp = !temp;
                isLeft[j] = temp;
            }
            temp = Left;
            for (int j = a+1; j < 4 ; j++) {
                temp = !temp;
                isLeft[j] = temp;
            }

            for (int j = 0; j < 4; j++) {
                if(isRotate[j]){
                    w[j].rotate(isLeft[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            if(w[i].isSouth[0])
                ans += Math.pow(2,i);
        }
        sb.append(ans);
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
