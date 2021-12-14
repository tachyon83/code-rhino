import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
        for(int i = 0; i < clothes.length; i ++) {
            map.put(clothes[i][1], map.getOrDefault(clothes[i][1], 0)+1);
        }
//         각 옷을 안입을 경우 +1
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            answer *= (entry.getValue()+1);
        }
//         옷을 아무것도 안입을 경우 -1
        return answer-1;
    }
}
