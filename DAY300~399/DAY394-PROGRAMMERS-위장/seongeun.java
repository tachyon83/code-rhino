import java.util.HashMap;
class Solution {
	public int solution(String[][] clothes) {
		HashMap<String, Integer> map=new HashMap<String, Integer>();
		for(int i=0;i<clothes.length;i++) { //value의 크기를 구할수 있다.
			map.put(clothes[i][1],map.getOrDefault(clothes[i][1],0)+1);
		}
		int answer = 1;
        for (int value : map.values()) {
            answer*=(value+1);
        }
        answer-=1;
        return answer;
    }
    
}
