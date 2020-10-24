#include <stack>
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int mx;
        int water=0;
        for(auto e:height){
            if(st.empty()){
                mx=e;
                st.push(e);
            }else if(e<mx){
                st.push(e);
            }else if(e>=mx){
                while(!st.empty()){
                    water+=mx-st.top();
                    st.pop();
                }
                mx=e;
                st.push(e);
            }     
        }
        if(!st.empty())mx=st.top();
        while(!st.empty()){
            if(st.top()<mx)water+=mx-st.top();
            if(st.top()>mx)mx=st.top();
            st.pop();
        }
        return water;
    }
};
