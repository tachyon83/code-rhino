#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double fail[501];

bool cmp(int a, int b) { 
    if(fail[a] == fail[b]) return a < b; // 실패율이 같다면 번호 오름차순으로
    else return fail[a] > fail[b]; // 실패율 내림차순으로
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(N + 1, 0);
    int user_num = stages.size();
    for(int i = 0; i < user_num; i++){  // 스테이지에 도전하고 있는 사람의 수를 계산한다
        if(stages[i] < N + 1) {
            cnt[stages[i]]++;   
        }
    }
    
    for(int i = 1; i < cnt.size(); i++){ 
        if(cnt[i] != 0) { // 스테이지에 도달한 유저가 있을 경우 실패율을 구한다
            fail[i] = (double)cnt[i] / user_num;
            user_num -= cnt[i]; // 현재 스테이지까지만 도달했으므로 다음부터 제외
        }
    }
    
    for(int i = 1; i <= N; i++){
        answer.push_back(i);
    }
    sort(answer.begin(),answer.end(),cmp); // 스테이지 정렬
    return answer;
}
