import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a=br.readLine();
        String b=br.readLine();
        int n=b.length();
        List<Character> list=new ArrayList<>();
        for (int i = 0; i < a.length(); i++) {
            char c=a.charAt(i);
            list.add(a.charAt(i));
            if(c==b.charAt(n-1)){
                int k=list.size();
                boolean flag=true;
                int j;
                for ( j=1; j < n+1; j++) {
                    if(k-j<0||list.get(k-j)!=b.charAt(n-j))
                        break;
                }
                if(j==n+1){
                    while (j-->1){
                        list.remove(list.size()-1);
                    }
                }
            }
        }
        if (list.size() > 0) {
            StringBuilder sb=new StringBuilder();
            for(char q:list){
                sb.append(q);
            }
            System.out.println(sb);
        }else {
            System.out.println("FRULA");
        }

    }
}
