import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

class Solution {

    static int ans = 0;
    static List<Integer> cnts;
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();
        for (String[] clothe : clothes) {
            String type = clothe[1];
            Integer cnt = map.get(type);
            if (cnt == null) {
                map.put(type, 1);
            } else {
                map.put(type, cnt + 1);
            }
        }
        cnts = new ArrayList<>(map.values());
        for (int i = 0; i < cnts.size(); i++) {
            comb(i, 1);
        }

        return ans;
    }

    void comb(int i, int num) {
        num *= cnts.get(i);
        ans += num;
        for (int j = i+1; j < cnts.size(); j++) {
            comb(j, num);
        }
    }

}
