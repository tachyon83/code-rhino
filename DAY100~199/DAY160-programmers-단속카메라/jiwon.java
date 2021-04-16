import java.io.*;
import java.util.*;


class Solution {
    public int solution(int[][] routes) {
        int answer = 1;
        
        Arrays.sort(routes, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int b[]){
                return a[1]-b[1]; //진출지점을 기준으로 정렬
            }
        });
        
        int min = routes[0][1];
        for(int i=0;i<routes.length;i++){
            if(min < routes[i][0]){
                min = routes[i][1];
                answer++;
            }
        }
        
        return answer;
    }
}
