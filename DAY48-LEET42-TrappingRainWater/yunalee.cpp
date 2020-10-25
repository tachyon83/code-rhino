#include <iostream>
#include <algorithm>

class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0){
            return 0;
        }
        
        int answer = 0;
        int gVal = 0;
        int gIdx = 0;
        for(int i = 0; i < height.size(); i++){
            if(gVal < height[i]){
                gVal = height[i];
                gIdx = i;
            }
        }
        
        int left = height[0];
        for(int i = 1; i < gIdx; i++){
            if(left - height[i] > 0){
                answer += (left - height[i]);
            }
            
            if(left < height[i]){
                left = height[i];
            }
        }
        
        int right = height[height.size() - 1];
        for(int i = height.size() - 2; i > gIdx; i--){
            if(right - height[i] > 0){
                answer += (right - height[i]);
            }
            
            if(right < height[i]){
                right = height[i];
            }
        }
        
        
        return answer;
    }
};
