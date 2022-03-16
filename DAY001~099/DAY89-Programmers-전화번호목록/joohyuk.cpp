#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#define endl '\n'
using namespace std;

unordered_set<string>nums;

bool solution(vector<string> phone_book) {
    for(string e:phone_book)nums.insert(e);
    for(string e:phone_book){
        for(int i=0;i<(int)e.size();++i){
            string temp=e.substr(0,i);
            if(nums.find(temp)!=nums.end())return 0;
        }
    }
    return 1;
}
