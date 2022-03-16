#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;

class Solution {
public:
    bool visited[10];
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            memset(visited,0,sizeof(visited));
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')continue;
                if(visited[board[i][j]-'1'])return 0;
                visited[board[i][j]-'1']=1;
            }
        }
        for(int j=0;j<9;++j){
            memset(visited,0,sizeof(visited));
            for(int i=0;i<9;++i){
                if(board[i][j]=='.')continue;
                if(visited[board[i][j]-'1'])return 0;
                visited[board[i][j]-'1']=1;
            }
        }
        for(int r=0;r<3;++r){
            for(int c=0;c<3;++c){
                memset(visited,0,sizeof(visited));
                for(int i=r*3;i<(r*3+3);++i){
                    for(int j=c*3;j<(c*3+3);++j){
                        if(board[i][j]=='.')continue;
                        if(visited[board[i][j]-'1'])return 0;
                        visited[board[i][j]-'1']=1;
                    }
                }
            }
        }
        return 1;
    }
};
