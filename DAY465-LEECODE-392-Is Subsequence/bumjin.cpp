#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int index = -1;
        for(char c: s){
            index = t.find(c, index + 1);
            if(index == string::npos) return false;
        }
        return true;
    }
};


int main() {

    return 0;
}
