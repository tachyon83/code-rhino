#include <string>
#include <vector>
#include <memory.h>
using namespace std;

bool deleted[31][31];

bool checkSquare(int y, int x, char type, vector<string> board) {
    // 2 x 2 블록 검사
    for(int i = y; i < y + 2; i++){
        for(int j = x; j < x + 2; j++){
            if(board[i][j] != type) return false;
        }
    }
    
    return true;
}

int countDeleteBlock(int y, int x) {
    int cnt = 0;
    
    for(int i = y; i < y + 2; i++){
        for(int j = x; j < x + 2; j++){
            if(deleted[i][j]) continue; // 이전에 지워질 블록이면 count하지 않는다.
            deleted[i][j] = true; // 지울 블록
            cnt++;
        }
    }
    
    return cnt;
}

void deleteBlock(int m, int n, vector<string>& board) {
    // 지워야할 블록들을 제거
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(deleted[i][j]) board[i][j] = ' ';
        }
    }
}

void moveBlock(int m, int n, vector<string>& board) {
    for(int i = 0; i < n; i++){ // 각 열에 대해
        for(int j = 1; j < m; j++){
            if(board[j][i] == ' '){ // 빈칸이라면 상단의 블록들을 아래로 당긴다.
                for(int k = j; k >= 1; k--){
                    if(board[k - 1][i] == ' ') continue; // 빈칸일시 당길 필요 없음
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = ' ';
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool flag = false;
    while(true) {
        flag = false;
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(board[i][j] == ' ') continue;
                if(checkSquare(i, j, board[i][j], board)) {
                    answer += countDeleteBlock(i, j);
                    flag = true;
                }
            }
        }
        if(!flag) break;
        deleteBlock(m, n, board);
        moveBlock(m, n, board);
        memset(deleted, false, sizeof(deleted));
    }
    
    return answer;
}
