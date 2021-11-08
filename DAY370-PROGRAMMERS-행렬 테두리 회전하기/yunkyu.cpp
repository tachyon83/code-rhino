#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int mat[101][101];

int rotate(int x1, int y1, int x2, int y2){
    int ret;
    
    // 시작값 덮어쓰기 전 저장
    int tmp = mat[x1][y1];
    ret = tmp;
    // 왼쪽 변 회전
    for(int i = x1; i < x2; i++){
        ret = min(ret,mat[i][y1]);
        mat[i][y1] = mat[i+1][y1];
    }
    // 아래쪽 변 회전
    for(int i = y1; i < y2; i++){
        ret = min(ret,mat[x2][i]);
        mat[x2][i] = mat[x2][i+1];
    }
    // 오른쪽 변 회전
    for(int i = x2; i > x1; i--){
        ret = min(ret,mat[i][y2]);
        mat[i][y2] = mat[i-1][y2];
    }
    // 위쪽 변 회전
    for(int i = y2; i > y1; i--){
        ret = min(ret,mat[x1][i]);
        mat[x1][i] = mat[x1][i-1];
    }
    mat[x1][y1 + 1] = tmp;
    
    return ret; // 회전한 값들 중 가장 작은 값 반환
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt = 0;
    // 행렬에 값 채우기
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            mat[i][j] = ++cnt;
        }
    }
   
    for(auto q : queries){
        answer.push_back(rotate(q[0],q[1],q[2],q[3]));
    }
    
    return answer;
}
