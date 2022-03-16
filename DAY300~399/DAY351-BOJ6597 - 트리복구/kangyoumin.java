package project;

import java.io.*;
import java.util.*;

public class Back_6597 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb=new StringBuilder();

    static HashMap<Character, Integer> map = new HashMap<>();
    static String p, in;
    
        static void post(int pL, int pR, int iL, int iR) {
        char rt = p.charAt(pL);
        Integer rtIdx = map.get(rt);

        int lSize = rtIdx - iL;
        if (lSize>0)
            post(pL + 1, pL + lSize, iL, rtIdx - 1);

        int rSize = iR - rtIdx;
        if (rSize > 0)
            post(pR - rSize + 1, pR, rtIdx + 1, iR);

        sb.append(rt);

    }
    
    public static void main(String[] args) throws Exception {
        while (true) {
            String s = br.readLine();
            if (s == null) {
                break;
            }
            StringTokenizer st = new StringTokenizer(s);
            p = st.nextToken();
            in = st.nextToken();

            for (int i = 0; i < in.length(); i++) {
                Character c = in.charAt(i);
                map.put(c, i);
            }
            post(0, p.length() - 1, 0, p.length() - 1);
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}
