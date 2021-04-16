
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int sz=(int)matrix.size();
        for(int i=0;i<sz;++i){
            if(matrix[0][i]>target){
                if(!i)return 0;
                for(int j=0;j<sz;++j)if(matrix[j][i-1]==target)return 1;
                return 0;
            }else if(matrix[0][i]==target)return 1;
            else if(i==sz-1){
                for(int j=0;j<sz;++j)if(matrix[j][sz-1]==target)return 1;
                return 0;
            }
        }
    }
};
