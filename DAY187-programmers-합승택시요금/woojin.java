// 처음에 각 a와 b의 최단거리를 dijkstra로 구하고 합승하는 구간을 각각 최단거리로 구해서 빼주는 방향으로 진행했는데 효율성 테스트에서 계속 걸려서 찾아본 결과
// 플로이드 알고리즘을 사용하는 것이 좋은 것을 찾아서 적용하였더니 맞았습니다.
class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        int[][] map = new int[n + 1][n + 1];
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                map[i][j] = 20000001;
            }
            map[i][i] = 0;
        }

        int start;
        int end;
        int cost;
        for (int i = 0; i < fares.length; i++) {
            start = fares[i][0];
            end = fares[i][1];
            cost = fares[i][2];

            map[start][end] = cost;
            map[end][start] = cost;
        }

        for (int k = 1; k < n + 1; k++) {
            for (int i = 1; i < n+1; i++) {
                for (int j = 1; j < n+1; j++) {
                    if(map[i][j] > map[i][k] + map[k][j]){
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }

        for (int i = 1; i < n+1; i++) {
            answer = Math.min(answer, map[s][i] + map[i][a] + map[i][b]);
        }
        return answer;
    }
}
