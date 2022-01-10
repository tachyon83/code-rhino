import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        Queue<String> queue = new LinkedList<>();
        
        if(cacheSize == 0) {
            return cities.length * 5;
        }
        
        for(int i = 0; i < cities.length; i++) {
            String str = cities[i].toLowerCase();
            
            if(queue.size() < cacheSize) {
                if(queue.contains(str)) {
                    int len = queue.size();
                    for(int j = 0; j < len; j++) {
                        if(!queue.peek().equals(str)) {
                            queue.offer(queue.peek());
                            queue.poll();
                        } else {
                            queue.poll();
                        }
                    }
                    queue.offer(str);
                    answer += 1;
                } else {
                    queue.offer(str);
                    answer += 5;
                }
            } else {
                if(queue.contains(str)) {
                    int len = queue.size();
                    for(int j = 0; j < len; j++) {
                        if(!queue.peek().equals(str)) {
                            queue.offer(queue.peek());
                            queue.poll();
                        } else {
                            queue.poll();
                        }
                    }
                    queue.offer(str);
                    answer += 1;
                } else {
                    queue.poll();
                    queue.offer(str);
                    answer += 5;
                }
            }
        }
        
        return answer;
    }
}
