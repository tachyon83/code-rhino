/**
 * String으로 단어를 하나씩 검사하면 시간 초과 발생 -> 그럼 어떻게 해결
 * 단어 10000개
 * 쿼리 500000
 * 시간 복잡도는 단어 10000 * 쿼리 50000 * 단어의 길이 1000
 * 시간 복잡도를 줄이는 방법은?
 * 단어를 비트를 이용해서 정수로 표현할 수 있다.
 * -> 문자열 -> 비트 마스크 -> 정수
 */
public class 단어암기_18119 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        //26개 초기화
        int mask = (1 << 27) - 1;

        int[] words = new int[n];
        for(int i = 0; i < words.length; i++) {
            String word = input.readLine();
            int num = 0;
            for(int j = 0; j < word.length(); j++) {
                num |= (1 << (word.charAt(j) - 'a' + 1));
                words[i] = num;
            }
        }


        for(int i = 0; i < m; i++){
            st = new StringTokenizer(input.readLine());
            int command = Integer.parseInt(st.nextToken());
            int ch = st.nextToken().charAt(0) - 'a' + 1;

           //1이면 삭제
            if(command == 1){
                //모음(a = 1, e = 5 ,i = 9 , o = 15,u = 21)이면 continue, 자음이면 삭제
                if(ch == 1 || ch == 5 || ch == 9 || ch == 15 || ch == 21) continue;
                mask &= ~(1 << ch);
            //2이면 추가
            }else{
                mask |= (1 << ch);
            }

            int count = 0;
            for(int word : words){
                //전체 mask와 비교할 word를 & 했을 때 word보다 크거나 같다면 word를 포함하는 것
                if((word & mask) >= word) count++;
            }

            sb.append(count).append("\n");
        }
        System.out.println(sb);

    }
}
