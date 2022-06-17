#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    unordered_map<char,int> map; 
    // 보너스 점수 매핑
    map.insert({'S', 1});
    map.insert({'D', 2});
    map.insert({'T', 3});
    
    vector<int> scores;
    int n = dartResult.length(), i = 0;
    while(i < n){
        int score;
        if(dartResult[i] == '1' && dartResult[i + 1] == '0'){ // 숫자가 10일 때
            score = pow(10, map[dartResult[i + 2]]);
            i += 3;
        }
        else{ // 숫자가 0 ~ 9일 때
            score = pow(dartResult[i] - '0', map[dartResult[i + 1]]); 
            i += 2;
        }
        
        scores.push_back(score);
        if(i < n) {
            if(dartResult[i] == '*'){ // 스타상을 받으면
                int n = scores.size();
                scores[n - 1] *= 2;
                if(n > 1) scores[n - 2] *= 2; // 첫 번째 기회가 아닐 시 이전 스코어도 두배
            }
            else if(dartResult[i] == '#'){ // 아차상을 받으면
                 scores[scores.size() - 1] *= -1; // 현재 스코어 마이너스로
            }
            else continue;
            i++;
        }
    }

    for(int i = 0; i < 3; i++) {
        answer += scores[i];
    }
    return answer;
}
