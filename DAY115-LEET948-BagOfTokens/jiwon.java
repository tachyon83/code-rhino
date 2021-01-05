//아직 못 품

class Solution {    
    public int bagOfTokensScore(int[] tokens, int P) {
        int tl = tokens.length;
        boolean check[] = new boolean [tl];
        int s = 0;
        
        
        if(tokens[0] > P){
            return 0;
        }
        int remember = 0;
        int k=0;
        
        for(int i=0;i<tl;i++){
            if(s>0){
                //(제일 큰) && (방문하지 않은) index == k
                for(k=tl-1;k>0;k--){
                    if(check[k]==false){
                        break;
                    }
                }
                s--;
                P+=tokens[k];
                check[k]=true;
            }
            
            if(P<tokens[i]){
                remember = i;
                break;
            }
            
            if(check[i]==false){    //방문한 적 없음
                P-=tokens[i];
                s++;
                
            }
            else{
                continue;
            }
           
            
        }
        return s;
        
        
    }
}
