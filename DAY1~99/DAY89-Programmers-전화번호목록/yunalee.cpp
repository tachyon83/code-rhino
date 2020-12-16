#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(string a, string b){
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    multimap<int, string> mm;
    for(auto pb : phone_book){
        int len = pb.length();
        for(int i = 1; i <= len; i++){
            int cnt = mm.count(i);
            if(cnt > 0){
                multimap<int, string>::iterator iter;
                for(iter = mm.lower_bound(i); iter != mm.upper_bound(i); iter++){
                    if(pb.substr(0, i) == iter->second){
                        return false;
                    }
                }
            }
        }
        mm.insert(make_pair(len, pb));
    }
    
    return answer;
}
