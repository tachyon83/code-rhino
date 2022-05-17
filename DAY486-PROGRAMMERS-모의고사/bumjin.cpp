#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> chk(3,0); // 0으로 초기화된 3개의 원소를 가진 벡터 (정답 맞힌 개수)
    
    int A[] = {1,2,3,4,5};
    int B[] = {2,1,2,3,2,4,2,5};
    int C[] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==A[i%5])
            chk[0]++;
        if(answers[i]==B[i%8])
            chk[1]++;
        if(answers[i]==C[i%10])
            chk[2]++;
    }
    
    int high_score = max(max(chk[0], chk[1]), chk[2]);

    for(int i=0; i<3; i++){
        if(chk[i]==high_score){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
