import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int prev=0,max=0,cnt=0;
        List<Integer> lis=new ArrayList<>();
        lis.add(Integer.parseInt(br.readLine()));
        for (int i = 0; i < n-1; i++) {
            int num=Integer.parseInt(br.readLine());
            int last=lis.get(lis.size()-1);
            if(last<num){
                lis.add(num);
            }else{
                int l=0,r=lis.size()-1;
                while (l<r){
                    int mid=(l+r)/2;
                    if(num>lis.get(mid))
                        l=mid+1;
                    else
                        r=mid;
                }
                lis.set(l,num);
            }
        }
        sb.append(n-lis.size());
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
