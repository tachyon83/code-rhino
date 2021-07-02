package DataStructure.문자열;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
4
Baha enter
Askar enter
Baha leave
Artem enter
 */
public class 회사에있는사람_7785 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        TreeSet<String> set = new TreeSet<>((o1, o2) -> o2.compareTo(o1));
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(input.readLine());
            String name = st.nextToken();
            String command = st.nextToken();
            if(command.equals("enter")) set.add(name);
            if(command.equals("leave")) set.remove(name);
        }
        for(String name : set) sb.append(name).append("\n");
        System.out.println(sb);
    }
}
