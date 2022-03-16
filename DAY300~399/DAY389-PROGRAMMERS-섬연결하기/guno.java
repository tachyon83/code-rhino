import java.util.Arrays;

class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int[] idxs = new int[n];

        Arrays.sort(costs,(o1, o2) -> o1[2]-o2[2]);
        int a = costs[0][0], b = costs[0][1], c = costs[0][2];
        int idx = 1;
        answer = c;
        idxs[a] = idx;
        idxs[b] = idx;
        for (int[] cost : costs) {

            boolean finished = true;
            for (int i : idxs) {
                if (i != 1) {
                    finished = false;
                    break;
                }
            }
            if(finished)
                break;

            a = cost[0];b = cost[1];c = cost[2];
            int idxA = idxs[a], idxB = idxs[b];

            if (idxA == 0 && idxB == 0) {
                idx++;
                idxs[a]=idx;
                idxs[b] = idx;
            } else if (idxA == 0 || idxB == 0) {
                if(idxA==0)
                    idxs[a] = idxB;
                else
                    idxs[b] = idxA;
            } else if (idxA != idxB) {
                int small = Math.min(idxA, idxB);
                int big = Math.max(idxA, idxB);

                for (int i = 0; i < n; i++) {
                    if(idxs[i]==big)
                        idxs[i] = small;
                }
            } else {
                answer -= c;
            }
            answer += c;
        }

        return answer;
    }
}
