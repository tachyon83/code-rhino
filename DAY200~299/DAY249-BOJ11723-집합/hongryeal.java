import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int bit = 0;

        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            String a = st.nextToken();
            if(a.equals("add")) bit = add(bit, Integer.parseInt(st.nextToken()));
            else if(a.equals("remove")) bit = remove(bit, Integer.parseInt(st.nextToken()));
            else if(a.equals("check")) check(bit, Integer.parseInt(st.nextToken()), sb);
            else if(a.equals("toggle")) bit = toggle(bit, Integer.parseInt(st.nextToken()));
            else if(a.equals("all")) bit = ~0;
            else if(a.equals("empty")) bit = 0;
        }
        System.out.println(sb.toString());
    }

    public static int add(Integer bit, int input){
        return bit | (1 << (input-1));
    }

    public static void check(Integer bit, int input, StringBuilder sb){
        int a = bit & (1 << (input-1));
        if(a >= 1) sb.append("1\n");
        else sb.append("0\n");
    }

    public static int remove(Integer bit, int input){
        return (bit | (1 << (input-1))) ^ (1 << (input-1));
    }

    public static int toggle(Integer bit, int input) {
        return bit ^ (1 << (input - 1));
    }
}
