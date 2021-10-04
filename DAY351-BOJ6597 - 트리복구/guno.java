import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }

    static Dictionary<Character, Integer> dict = new Hashtable<>();
    static String pre, in;
    public static void main(String[] args) throws Exception {
        while (true) {
            String s = br.readLine();
            if (s==null) {
                break;
            }
            st = new StringTokenizer(s);
            pre = st.nextToken();
            in = st.nextToken();

            for (int i = 0; i < in.length(); i++) {
                Character c = in.charAt(i);
                dict.put(c, i);
            }
            post(0, pre.length() - 1, 0, pre.length() - 1);
            sb.append("\n");
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void post(int preL, int preR, int inL, int inR) {
        char root = pre.charAt(preL);
        Integer rootIdx = dict.get(root);

        int leftTreeSize = rootIdx - inL;
        if (leftTreeSize>0)
            post(preL + 1, preL + leftTreeSize, inL, rootIdx - 1);

        int rightTreeSize = inR - rootIdx;
        if (rightTreeSize > 0)
            post(preR - rightTreeSize + 1, preR, rootIdx + 1, inR);

        sb.append(root);

    }


}
