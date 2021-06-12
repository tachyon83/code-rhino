/**
 * 최대한 많은 마을을 거쳐가면서 상자를 내려야 한다.
 * 처음에 출발지에서 많은 상자를 가지고 가는 것을 생각했는데
 * 이렇게 간단한 문제는 아닐거라고 생각했고 반례를 찾았다.
 * 그래서 그 다음으로 생각한게 출발지와 도착지의 거리가 짧은 기준이였고
 * 정렬의 기준이 너무 많아 지는 것 같아서 결국 힌트를 보고 도착지 기준으로 정렬해야 하는 것을 얻었따.
 */
public class 택배_8980 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());

        int box[] = new int[n + 1];
        int capacity = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(input.readLine());
        ArrayList<int[]> list = new ArrayList<>();

        for(int i = 0; i < m ; i++){
            st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            list.add(new int[]{start, end, weight});
        }

        //받는 마을 순으로 오름 차순 정리, 보내는 마을 순으로 오름 차순 정리
        list.sort((o1, o2) -> {
            if (o1[1] - o2[1] == 0) {
                return o1[0] - o2[0];
            } else {
                return o1[1] - o2[1];
            }
        });

        int result = 0;

        for(int i = 0; i < list.size(); i++){
            int[] send = list.get(i);
            int start = send[0];
            int end = send[1];
            int weight = send[2];

            //매 도착 마을에 내릴 수 있는 최대 무게를 정한다.
            //더한 값이 최대 용량 보다 작으면 삽입
            int min = weight;
            for(int j = start; j < end; j++){
                //더할 수 있는 최소 값 찾기
                if(box[j] + weight > capacity)
                    min = Math.min(capacity - box[j],min);
            }

            result += min;

            for(int j = start; j < end; j++)
                box[j] += min;
        }

        System.out.println(result);
    }
}
