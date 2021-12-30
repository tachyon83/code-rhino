import java.util.*;

class Solution {
    static int tempN;
    TreeSet<Integer>[] arr;
    
    public TreeSet<Integer> getNum(int n) {
        if((arr[n]!=null) && !arr[n].isEmpty())
            return arr[n];
        
        int num = 0;
        for(int i=0; i<n ; i++)
            num = 10*num + tempN;
        
        TreeSet<Integer> temp = new TreeSet<>();
        temp.add(num);
        
        for(int i=1; i<n; i++) {
            int j = n-i;
            TreeSet<Integer> from = getNum(i);
            TreeSet<Integer> to = getNum(j);
            for(int n1 : from) {
                for(int n2 : to) {
                    temp.add(n1+n2);
                    temp.add(n1-n2);
                    temp.add(n1*n2);
                    if(n2!=0) temp.add(n1/n2);
                }
            }
        }
        return arr[n] = temp;
    }
    public int solution(int N, int number) {
        int answer = 0;
        tempN = N;
        arr = new TreeSet[10];
        for(int i=1; i<=8; i++) {
            getNum(i);
            if(arr[i].contains(number)) 
                return i;
        }
        
        return -1;
    }
}
