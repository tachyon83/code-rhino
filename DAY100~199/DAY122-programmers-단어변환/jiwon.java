//푸는중,,,
class Solution {
    public int size(String begin){
        char[] temp = begin.toCharArray();
        return temp.length;
    }
    public int diff(String comp1, String comp2){
        char[] c1 = comp1.toCharArray();
        char[] c2 = comp2.toCharArray();
        int c = 0;
        int wordLength = c1.length;
           for(int i=0;i<wordLength;i++){
               if(c1[i]==c2[i]){
                    c++;
                }
                if(c>wordLength){
                    break;
                }
            }
        int result = wordLength - c;
        return result;
    }
    public int solution(String begin, String target, String[] words) {
        Queue<String> q = new LinkedList<String>();
        
        int count=0;
        int wordsArrayLength = words.length;
        int wordLength = size(begin);
        int i=0;
        int visit[] = new int [wordsArrayLength];
        q.offer(begin);
        
        while(true){
            if(i==wordsArrayLength-1){  //words배열 모두 돌았으면 while Out!
                break;
            }
             if(visit[i]==1){   //이미 방문했거나
                i++;
            }
            String compare1 = q.peek();
            String compare2 = words[i];
           
           
            if(diff(compare1, compare2)==1){
                q.offer(compare2);
                count++;
           
                //target과 검사
                if(diff(compare2,target)==1){
                    break;
                }
            }
        }
         return count;
    }
       
}