#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> um;
    for(auto p:clothes){
        int i=0;
        for(string e:p){
            if(i){
                if(um.find(e)==um.end())um[e]=1;
                um[e]++;
            }
            i++;
        }
    }
    int answer = 1;
    for(auto e:um)answer*=e.second;
    return answer-1;
}
