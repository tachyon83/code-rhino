import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {




    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));


        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());


        HashMap<Integer,Integer> map = new LinkedHashMap<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < n;i++){
            int cur = Integer.parseInt(st.nextToken());
            if(map.containsKey(cur)){
               map.put(cur,map.get(cur)+1);

            }else{
                map.put(cur,1);
            }

        }

        Integer key[] = map.keySet().toArray(new Integer[map.size()]);

        Arrays.sort(key, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(map.get(o2),map.get(o1));
            }
        });
        
        StringBuilder sb = new StringBuilder();

        for(int num : key){
            for(int  i = 0 ; i < map.get(num);i++){
                sb.append(num+" ");
            }

        }


        System.out.println(sb.toString());

    }


}
