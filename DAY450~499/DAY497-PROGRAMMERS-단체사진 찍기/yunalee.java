import java.util.HashMap;

class Solution {
    int position[] = new int[8];
    boolean visited[] = new boolean[8];
    int count = 0;
    HashMap<Character, Integer> map = new HashMap<>();
    
    void solved(int index, String[] data) {
        if(index == 8) {
            if(isEnd(data)) {
                count++;
            }
            return;
        }
        
        for(int i = 0; i < 8; i++) {
            if(!visited[i]) {
                visited[i] = true;
                position[index] = i;
                solved(index + 1, data);
                visited[i] = false;
            }
        }
    }
    
    boolean isEnd(String[] data) {
        for(int i = 0; i < data.length; i++) {
            int first = map.get(data[i].charAt(0));
            int second = map.get(data[i].charAt(2));
            int gap = data[i].charAt(4) - '0';
            int firstPosition = position[first];
            int secondPosition = position[second];
            
            switch(data[i].charAt(3)) {
                case '=':
                    if(Math.abs(firstPosition - secondPosition) - 1 != gap) {
                        return false;
                    }
                    break;
                case '>':
                    if(Math.abs(firstPosition - secondPosition) - 1 <= gap) {
                        return false;
                    }
                    break;
                case '<':
                    if(Math.abs(firstPosition - secondPosition) - 1 >= gap) {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
    
    public int solution(int n, String[] data) {
        int answer = 0;
        
        map.put('A', 0);
        map.put('C', 1);
        map.put('F', 2);
        map.put('J', 3);
        map.put('M', 4);
        map.put('N', 5);
        map.put('R', 6);
        map.put('T', 7);
        
        solved(0, data);
        
        return count;
    }
}
