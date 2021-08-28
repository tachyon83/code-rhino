//미완성
public class 박스채우기_1493 {

    private static int result = 0;
    private static boolean check = false;
    private static void fillCube(int length, int width, int height, TreeMap<Integer, Integer> box) {

        if(length == 0 || width == 0 || height == 0) return;
        for(int idx : box.keySet()){
            //길이가 idx인 큐브의 크기
            int cubeCount = box.get(idx);
            int cubeLen = 1 << idx;
            if(cubeLen > 0 && length - cubeLen >= 0 || width - cubeLen >= 0 || height - cubeLen >= 0) {
                box.put(idx, cubeCount - 1);
                result++;
                fillCube(length - cubeLen, width, height, box);
                fillCube(length, width - cubeLen, height, box);
                fillCube(length, width, height - cubeLen, box);
                return;
            }
        }
        check = true;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        TreeMap<Integer, Integer> box = new TreeMap<>((o1, o2) -> o2 - o1);
        int length = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());

        int n = Integer.parseInt(input.readLine());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(input.readLine());
            int idx = Integer.parseInt(st.nextToken());
            int cnt = Integer.parseInt(st.nextToken());
            box.put(idx,cnt);
        }

        fillCube(length, width, height, box);
        System.out.println(check);
        System.out.println(result);
    }
}
