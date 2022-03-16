import java.util.*;

class Solution {

    static Map<String, Integer> map;

    public String[] solution(String[] orders, int[] course) {
        List<String> ans = new ArrayList<>();
        for (int len : course) {
            map = new HashMap<>();
            for (String order : orders) {
                if(len>order.length())
                    continue;
                char[] chars = order.toCharArray();
                Arrays.sort(chars);
                String s = new String(chars);
                comb(s, len, "");
            }
            Optional<Integer> temp = map.values().stream().max(Integer::compareTo);
            if (temp.isPresent()) {
                int max = temp.get();
                if (max >= 2) {
                    map.keySet().stream().filter(s -> max == map.get(s))
                            .forEach(ans::add);
                }
            }
        }
        ans.sort(String::compareTo);

        return ans.toArray(String[]::new);
    }

    void comb(String order,int cnt, String menu) {
        if (cnt == 0) {
            if (map.containsKey(menu)) {
                int num = map.get(menu);
                map.put(menu, num + 1);
            } else {
                map.put(menu, 1);
            }
        }
        for (int i = 0; i < order.length(); i++) {
            comb(order.substring(i + 1), cnt-1, menu + order.charAt(i));
        }

    }

}
