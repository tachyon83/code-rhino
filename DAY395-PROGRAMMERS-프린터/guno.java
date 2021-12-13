import java.util.*;
import java.util.stream.Collectors;

class Solution {

    class Node {
        int priority,location;
        public Node(int location, int priority) {
            this.location = location;
            this.priority = priority;
        }
    }

    public int solution(int[] priorities, int location) {
        int answer = 0;
        Deque<Node> deque = new ArrayDeque<>();
        Deque<Integer> maxList = Arrays.stream(priorities).boxed().sorted(Comparator.reverseOrder())
                .collect(Collectors.toCollection(ArrayDeque::new));

        for (int i = 0; i < priorities.length; i++) {
            deque.add(new Node(i, priorities[i]));
        }

        while (true) {
            Node node = deque.pollFirst();
            if (node.priority == maxList.getFirst()) {
                maxList.pollFirst();
                answer++;
                if (node.location == location) {
                    break;
                }
            } else {
                deque.add(node);
            }
        }

        return answer;
    }
}
