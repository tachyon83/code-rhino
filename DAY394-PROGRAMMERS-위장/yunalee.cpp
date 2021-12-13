#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> um;
    int answer = 1;
    unordered_map<string, int>::iterator iter;
    
    for(int i = 0; i < clothes.size(); i++){
        iter = um.find(clothes[i][1]);
        if(iter == um.end()){    //없는 옷의 종류라면
            um.insert(make_pair(clothes[i][1], 2)); //각 옷의 종류마다 선택하지 않는 경우 1 + 옷 1개 = 2
        }else{
            um[clothes[i][1]]++;
        }
    }
    
    //옷이 한가지 종류이면 조합할 경우가 없으므로 옷의 가지 수 만큼 반환
    if(um.size() == 1){
        return clothes.size();
    }
    
    for(iter = um.begin(); iter != um.end(); iter++){
        answer *= iter->second;
    }
    answer -= 1;    //옷을 모두 안입는 경우는 없으므로 -1
    
    return answer;
}
