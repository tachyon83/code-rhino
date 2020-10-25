#include <iostream>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<string> tmpVc;
        for(int i = 0; i < strs.size(); i++){
            vector<string> subVc;
            string str = strs[i];
            sort(str.begin(), str.end());
            
            bool flag = false;
            for(int j = 0; j < tmpVc.size(); j++){
                if(str == tmpVc[j]){
                    answer[j].push_back(strs[i]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                subVc.push_back(strs[i]);
                tmpVc.push_back(str);
                answer.push_back(subVc);
            }
        }
        
        return answer;
    }
};
