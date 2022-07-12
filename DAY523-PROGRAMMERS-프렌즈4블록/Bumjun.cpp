#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;



int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int i = 1;
    vector<pair<int, int>> v;
    bool flag = true;
    
    while(true){
        flag = false;
        for(int i = 1; i < board.size(); i++){
            for(int j = 0; j < board[i].size() - 1; j++){
                if(board[i][j] != ' ' && (tolower(board[i][j]) == tolower(board[i - 1][j])) &&
                (tolower(board[i][j]) == tolower(board[i][j + 1])) &&
                (tolower(board[i][j]) == tolower(board[i - 1][j + 1]))){
                    board[i][j] = tolower(board[i][j]);
                    board[i - 1][j] = board[i][j];
                    board[i][j + 1] = board[i][j];
                    board[i - 1][j + 1] = board[i][j];
                    flag = true;
                }
            }
        }
        if(flag == false)
            break;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] >= 'a' && board[i][j] <= 'z'){
                    board[i][j] = ' ';
                    answer++;
                }
            }
        }
        for(int i = board.size() - 1; i >= 0; i--){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == ' '){
                    for(int z = i - 1; z >= 0; z--){
                        if(board[z][j] != ' '){
                            board[i][j] = board[z][j];
                            board[z][j] = ' ';
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}
