import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Info{
        String parent;
        ArrayList<String> name;

        public Info(String parent, ArrayList<String> name) {
            this.parent = parent;
            this.name = name;
        }

        public void sort(){
            name.sort(new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return o1.compareTo(o2);
                }
            });
        }

    }


    static Map<String,Integer> name;
    static ArrayList<String> list[];
    static int num[];
    static String getName[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n];
        num = new int[n];
        getName = new String[n];
        name = new HashMap<String,Integer>();

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0 ; i < n ;i++){
            String input = st.nextToken();
            name.put(input,i);
            list[i] = new ArrayList<String>();

            getName[i] = input;
        }

        int m = Integer.parseInt(br.readLine());


        for(int i = 0 ; i< m ; i++){
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            String b = st.nextToken();

            int numa = name.get(a);
            int numb = name.get(b);


            list[numb].add(a);
            num[numa]++;

        }

        topology(n);

    }

    public static void topology(int n){
        Queue<Integer> que = new LinkedList<Integer>();
        ArrayList<String> root = new ArrayList<String>();
        ArrayList<Info> info = new ArrayList<Info>();

        for(int i= 0 ; i < num.length;i++){
            if(num[i] == 0){
                que.add(i);
                root.add(getName[i]);
            }
        }

        for(int i = 0 ; i < n;i++){
            if(que.isEmpty())return;
            int cur = que.poll();

            int cnt = 0;
            ArrayList<String> child = new ArrayList<String>();
            for(int j = 0 ;j  < list[cur].size();j++){
                int getIdx = name.get(list[cur].get(j));
                num[getIdx]--;

                if(num[getIdx] == 0) {
                    cnt++;
                    que.add(getIdx);
                    child.add(list[cur].get(j));
                }

            }

            ArrayList<String> childinfo = new ArrayList<String>();
            for(String name : child){
                childinfo.add(name);
            }
            Info data = new Info(getName[cur],childinfo);

            info.add(data);

        }


        System.out.println(root.size());
        root.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });

        for(String name : root){
            System.out.print(name+" ");
        }
        System.out.println();

        info.sort(new Comparator<Info>() {
            @Override
            public int compare(Info o1, Info o2) {
                return o1.parent.compareTo(o2.parent);
            }
        });

        for(Info data : info){
            data.name.sort(new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return o1.compareTo(o2);
                }
            });
            System.out.print(data.parent+" "+data.name.size()+" ");
            for(String name : data.name){
                System.out.print(name+" ");
            }
            System.out.println();
        }


    }




}
