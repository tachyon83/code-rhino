/**
 * 비트마스킹은
 * 어떤 옵션들이 선택되었는지 한 번에 확인하고자 할 때,
 * 어떤 정점들을 거쳤는지/방문했는지 한번에 확인할 때,
 * 어떤 물건들을 챙겼는지 한번에 확인할 때,
 * 등과 같이, 어떠한 선택 옵션이나 필요 준비물(?)등이 선택되었는지, 방문했는지 등을 단 한 번의 연산으로 확인할 수 있게 해 준다.
 */
//0다음수는 1, 9 다음수는 8, 나머지는 +1,-1 2가지
public class 계단수_1562 {

    private static long getCal(int n) {

        //index , index에 들어가는 수, 비트마스킹으로 0~9표현
        long[][][] dp = new long[101][10][1024];

        //초기화
        for(int i = 1; i <= 9; i++)
            dp[1][i][1 << i] = 1;


        for(int i = 2; i <= n; i++){

            for(int j = 0; j <= 9; j++){

                //k = 10
                for(int k = 0; k < 1024; k++){

                    //|를 통해서 k에 1 << j 추가
                    int bit = k | (1 << j);

                    if(j == 0){
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][1][k]) % 1000000000;
                    }else if(j == 9){
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][8][k]) % 1000000000;
                    }else{
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % 1000000000;
                    }
                }

            }
        }

        long sum = 0;
        for(int i = 0; i <= 9; i++){
            sum = (sum + dp[n][i][1023]) % 1000000000;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        System.out.println(getCal(n));
    }
}
