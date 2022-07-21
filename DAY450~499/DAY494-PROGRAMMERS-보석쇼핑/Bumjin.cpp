#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> m;
    set<string> num(gems.begin(), gems.end());
    int Min, start = 0, end = 0;

    for(auto& s : gems){
        m[s]++;
        if(m.size() == num.size()) break;
        end++;
    }
    Min = end - start;  //구간중 가장 짧은 구간을 구해야 하므로
    answer[0] = start + 1;
    answer[1] = end + 1;

    while(end < gems.size()){
        string key = gems[start];
        m[key]--; start++;

        if(m[key] == 0){
            end++;
            for(; end < gems.size(); end++){
                m[gems[end]]++;
                if(key == gems[end])
                    break;
            }
            if(end == gems.size()) break;
        }
        if(Min > end - start){
            answer[0] = start + 1;
            answer[1] = end + 1;
            Min = end - start;
        }

    }

    return answer;
}
