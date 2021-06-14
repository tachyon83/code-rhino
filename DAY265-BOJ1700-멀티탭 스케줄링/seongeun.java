public class 멀티탭스케줄링_1700 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int capa = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        Set<Integer> set = new HashSet<>();
        st = new StringTokenizer(input.readLine());
        for(int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int result = 0;

        for(int i = 1; i <= n; i++){
            int index = arr[i];
            //플러그인이 남았다면 채우기
            if(set.size() < capa){
                set.add(index);
            }else{
                //플러그인에 포함하고 있다면 continue
                if(set.contains(index))
                    continue;

                //Set에 들어있는 수중에서 가장 늦게 사용되는 것을 찾는다.
                LinkedList<Integer> iter = new LinkedList<>(set);
                for(int j = i; j <= n; j++){
                    if(iter.contains(arr[j]))
                        iter.remove((Integer) arr[j]);
                    //플러그인이 1인 경우 고려 = 1 -> <= 1로 변경
                    if(iter.size() <= 1) break;
                }
                set.remove(iter.get(0));
                set.add(index);
                result++;
            }
        }
        System.out.println(result);
    }
}
