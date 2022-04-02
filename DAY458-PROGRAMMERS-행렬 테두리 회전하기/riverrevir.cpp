#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns, 0));
    int number = 1;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = number++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;
        int min = rows * columns + 1;
        int before = board[x1 + 1][y1];
        
        for(int j = y1; j <= y2; j++){
            int tmp = board[x1][j];
            board[x1][j] = before;
            before = tmp;
            min = min < board[x1][j] ? min : board[x1][j];
        }
        
        for(int i = x1 + 1; i <= x2; i++){
            int tmp = board[i][y2];
            board[i][y2] = before;
            before = tmp;
            min = min < board[i][y2] ? min : board[i][y2];
        }
        
        for(int j = y2 - 1; j >= y1; j--){
            int tmp = board[x2][j];
            board[x2][j] = before;
            before = tmp;
            min = min < board[x2][j] ? min : board[x2][j];
        }
        
        for(int i = x2 - 1; i > x1; i--){
            int tmp = board[i][y1];
            board[i][y1] = before;
            before = tmp;
            min = min < board[i][y1] ? min : board[i][y1];
        }
        
        answer.push_back(min);
    }
    
    return answer;
}
