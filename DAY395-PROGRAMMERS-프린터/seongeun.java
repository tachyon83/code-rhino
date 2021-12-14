import java.util.*;
    
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        int size = priorities.length;
        
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < priorities.length ; i++)
            q.add(new int[]{i,priorities[i]});
        
        while(!q.isEmpty()){
            //1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
            int tmp[] = q.poll();
            //2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
            boolean check = false;
            Iterator<int[]> iterator = q.iterator();
            while(iterator.hasNext()){
                int compareData[] = iterator.next();
                if(tmp[1] < compareData[1]){
                    check = true;
                    break;
                }
            }
            if(check){
                q.add(new int[]{tmp[0],tmp[1]});
                //3 . 그렇지 않으면 J를 인쇄합니다.
            }else{
                if(tmp[0] == location){
                    break;
                }else{
                    answer++;
                }
            }
        }
        return answer;
    }
}
