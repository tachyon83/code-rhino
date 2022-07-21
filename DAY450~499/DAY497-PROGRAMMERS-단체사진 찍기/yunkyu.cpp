#include <string>
#include <vector>
#include <memory.h>
#include <cmath>
using namespace std;

char kf[] = {'A','C','F','J','M','N','R','T'};
bool selected[9];

bool check(string s, vector<string> data) {
    for(auto line : data) { 
        int fromIdx = s.find(line[0]);
        int toIdx = s.find(line[2]);
        char oper = line[3];
        int len = line[4] - '0';
    
        int diff = toIdx - fromIdx > 0 ? toIdx - fromIdx : fromIdx - toIdx; // 두 카카오 프렌즈 사이의 거리
        diff--;
        
        // 조건을 만족하는지 확인
        if(oper == '=' && diff != len){
            return false;
        }
        else if(oper == '>' && diff <= len){
            return false;
        }
        else if(oper == '<' && diff >= len){
            return false;
        }
    }
    
    return true;
}

int DFS(string acc, int cnt, vector<string> data) {
    if(cnt == 8){ // 모두 줄을 세웠을 때
        if(check(acc, data)) return 1; // 모든 조건을 만족한다면
        else return 0;
    }
    
    int ret = 0;
    for(int i = 0; i < 8; i++){
        if(!selected[i]) {
            // 모든 순열을 구함
            selected[i] = true;
            ret += DFS(acc + kf[i], cnt + 1, data);
            selected[i] = false;
        }
    }
    
    return ret;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    memset(selected, false, sizeof(selected));
    
    answer = DFS("", 0, data);
    
    return answer;
}
