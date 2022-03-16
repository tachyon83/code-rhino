import java.util.*;

class Solution {

    static Map<Long, Long> map = new HashMap<>();
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for (int i = 0; i < room_number.length; i++) {
            long insertId = insert(room_number[i]);
            answer[i] = insertId;
        }
        
        return answer;
    }
    
    long insert(long room_id) {
        List<Long> temp = new ArrayList<>();
        while (map.containsKey(room_id)) {
            temp.add(room_id);
            room_id = map.get(room_id);
        }
        for (Long id : temp) {
            map.put(id, room_id);
        }
        map.put(room_id, room_id + 1);
        return room_id;
    }


}
