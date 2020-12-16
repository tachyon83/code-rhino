class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz=(int)triangle.size();
        for(int i=sz-1;i>=0;--i){
            for(int j=0;j<=i;++j){
                if(i+1<sz){
                    triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
                }
            }
        }
        return triangle[0][0];
    }
};
