#include <iostream>

class Solution {
private:
    bool flag=0;
    int sz=301;
    bool vis[301];
public:
    Solution(){fill(vis,vis+sz,0);}
    int firstMissingPositive(vector<int>& nums) {
        for(auto e:nums)if(e<sz&&0<=e)vis[e]=1;
        int ans=1;
        for(int i=1;i<=(int)nums.size();++i){
            if(!vis[i]){
                ans=i;
                flag=1;
                break;
            }
        }
        if(!flag)ans=(int)nums.size()+1;
        return ans;
    }
};
