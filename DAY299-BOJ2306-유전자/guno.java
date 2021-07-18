package 유형.DP;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;


public class Main {
    public static int[][] arr=new int[500][500];
    public static String s;
    public static int dfs(int l,int r){
        if(l>=r)
            return 0;
        if(arr[l][r]!=-1)
            return arr[l][r];
        int temp=-1;
        for(int i=l;i<r;i++){
            temp=Math.max(temp,dfs(l,i)+dfs(i+1,r));
        }
        if((s.charAt(l)=='a'&&s.charAt(r)=='t')||(s.charAt(l)=='g'&&s.charAt(r)=='c'))
            temp=Math.max(temp,dfs(l+1,r-1)+2);
        arr[l][r]=temp;
        return temp;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s=br.readLine();
        for (int[] a:arr) {
            Arrays.fill(a,-1);
        }
        System.out.print(dfs(0,s.length()-1));
    }
}
