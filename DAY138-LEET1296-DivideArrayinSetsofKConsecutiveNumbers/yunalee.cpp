class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {        
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            if(it.second){
                int key = it.first;
                int val = it.second;
                
                for(int i = 0; i < k; i++){
                    int tmp = key + i;
                    if(m[tmp] < val){
                        return false;
                    }else{
                        m[tmp] -= val;
                    }
                }
            }
        }
        
        return true;
    }
};
