import java.io.*;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st= new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashMap<String,Integer> map = new HashMap<>();
        for(int i = 0 ; i < n; i++){
            String word = br.readLine();
            if(word.length() >=m){

                if(map.containsKey(word)){
                    map.replace(word,map.get(word)+1);
                }else{
                    map.put(word,1);
                }
            }

        }

        String list[] = map.keySet().toArray(new String[map.size()]);

        Arrays.sort(list);

        Arrays.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.length()-o1.length();
            }
        });

        Arrays.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return map.get(o2)-map.get(o1);
            }
        });


        StringBuilder sb = new StringBuilder();
        for(String str : list){

            sb.append(str+"\n");
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(sb.toString());
        bw.close();


    }
}
