class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        int point=0;
        int n=(int)tokens.size();
        sort(tokens.begin(),tokens.end());
        int left=0;
        int right=n-1;
        while(left<=right){
            if(P>=tokens[left]){
                P-=tokens[left];
                point++;
                left++;
            }else if(point>0){
                if(left+1<right){
                    P+=tokens[right];
                    point--;
                    right--;                   
                }else break;
            }else if(point<1)break;
        }
        return point;       
    }
};
