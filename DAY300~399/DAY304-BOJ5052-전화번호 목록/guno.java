import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int T=Integer.parseInt(br.readLine());
        while (T-->0){
            int n=Integer.parseInt(br.readLine());
            List<char[]> nums=new ArrayList<>();
            while (n-->0){
                nums.add(br.readLine().toCharArray());
            }
            Node root=new Node();
            boolean flag=true;
            for(char[] num:nums){
                Node current=root;
                for(int i=0;i<num.length;i++){
                    char c=num[i];
                    if(current.children[c-'0']==null){
                        current.children[c-'0']=new Node();
                        if(i==num.length-1)
                            current.children[c-'0'].isEnd=true;
                    }else {
                        if(i==num.length-1||current.children[c-'0'].isEnd){
                            flag=false;
                            break;
                        }
                    }
                    current=current.children[c-'0'];

                }
                if(!flag)
                    break;
            }
            sb.append(flag?"YES\n":"NO\n");
        }
        System.out.print(sb);
    }
}
class Node{

    Node[] children=new Node[10];
    boolean isEnd=false;


}
