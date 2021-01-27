class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rowLen = mat.size();
        int colLen = mat[0].size();
        int arr[rowLen][colLen];
        
        for(int i = 0; i < rowLen; i++){
            int cnt = 0;
            for(int j = colLen - 1; j >= 0; j--){
                if(mat[i][j] == 1){
                    cnt ++;
                }else{
                    cnt = 0;
                }
                arr[i][j] = cnt;
            }
        }
        
        int answer = 0;
        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                int maxNum = 987987987;
                
                for(int p = i; p < rowLen; p++){
                    maxNum = min(maxNum, arr[p][j]);
                    answer += maxNum;
                }
            }
        }
        
        return answer;
    }
};
