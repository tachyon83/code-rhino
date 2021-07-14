
public class 단어섞기_9177 {

    private static String getMakeString(String str1, String str2, String result) {

        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[201][201];
        q.add(new int[]{0, 0});

        while(!q.isEmpty()) {
            int[] indexes = q.poll();
            int index1 = indexes[0];
            int index2 = indexes[1];
            int index3 = index1 + index2;

            if( index1 == str1.length() && index2 == str2.length()) return "yes";
            /**
             * 기존의 코드는 continue를 사용했다. 하지만 continue를 했을 때 미쳐 생각하지 못한점이 있다.
             * index1에서 continue가 걸렸을 경우 index2까지 가지 못한다는 점을 숙지 하지 못했다.
             * 그래서 BFS를 사용할 때 여러개의 조건문이 있을 경우 continue보다는 if문 안에서 &&로 조건을 만족하도록 표현하는 것이 좋다.
             */
            if(index1 < str1.length() && str1.charAt(index1) == result.charAt(index3) && !visited[index1 + 1][index2]) {
                q.add(new int[] {index1 + 1, index2});
                visited[index1 + 1][index2] = true;
            }
            if(index2 < str2.length() && str2.charAt(index2) == result.charAt(index3) && !visited[index1][index2 + 1]) {
                q.add(new int[] {index1, index2 + 1});
                visited[index1][index2 + 1] = true;
            }
        }

        return "no";
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            String str1 = st.nextToken();
            String str2 = st.nextToken();
            String target = st.nextToken();
            sb.append("Data set ").append(i + 1).append(": ").append(getMakeString(str1, str2,target)).append("\n");
        }
        System.out.println(sb);
    }
}
