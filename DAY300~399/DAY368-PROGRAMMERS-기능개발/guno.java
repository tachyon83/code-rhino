import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int len = progresses.length;
        List<Integer> ans = new ArrayList<>();
        int[] times = IntStream.range(0, len)
                .map(i -> (int) Math.ceil((double) (100 - progresses[i]) / speeds[i])).toArray();
        int now = times[0], cnt = 0;
        for (int time : times) {
            if (time > now) {
                now = time;
                ans.add(cnt);
                cnt=1;
            } else {
                cnt++;
            }
        }
        ans.add(cnt);

        return ans.stream().mapToInt(i->i).toArray();
    }
}
