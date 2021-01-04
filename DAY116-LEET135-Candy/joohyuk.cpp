#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz=(int)ratings.size();
        vector<int>candies;
        for(int i=0;i<sz;++i)candies.push_back(1);

        bool complete=0;
        while(!complete){
            complete=1;
            for(int i=1;i<sz-1;++i){
                if((ratings[i]>ratings[i-1])&&(candies[i]<=candies[i-1])){
                    complete=0;
                    candies[i]=candies[i-1]+1;
                }
                if((ratings[i]<ratings[i+1])&&(candies[i]>=candies[i+1])){
                    complete=0;
                    candies[i+1]=candies[i]+1;
                }
            }
        }

        int t=0;
        for(int i=0;i<sz;++i)t+=ratings[i];
        return t;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    Solution s=Solution();
    vector<int>test;
    test.push_back(1);
    test.push_back(0);
    test.push_back(2);
    s.candy(test);

    return 0;
}
