#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;

class Solution {
private:
    int rowStat[9],colStat[9],sectionStat[3][3];

public:
    void checkSudoku(vector<vector<char>>& board){
        memset(rowStat,0,sizeof(rowStat));
        memset(colStat,0,sizeof(colStat));
        memset(sectionStat,0,sizeof(sectionStat));
        for(int r=0;r<3;++r){
            for(int c=0;c<3;++c){
                for(int i=r*3;i<(r*3+3);++i){
                    for(int j=c*3;j<(c*3+3);++j){
                        if(board[i][j]=='.')continue;
                        rowStat[i]|=1<<(board[i][j]-'1');
                        colStat[j]|=1<<(board[i][j]-'1');
                        sectionStat[i/3][j/3]|=1<<(board[i][j]-'1');
                    }
                }
            }
        }
    }
    bool isPossible(int i,int j,int k){
        if(rowStat[i]&1<<k||colStat[j]&1<<k||sectionStat[i/3][j/3]&1<<k)return 0;
        return 1;
    }
    bool fillup(vector<vector<char>>& board,int num){
        if(num==9*9)return 1;
        int i=num/9,j=num%9;
        if(board[i][j]!='.')return fillup(board,num+1);
        for(int k=0;k<9;++k){
            if(!isPossible(i,j,k))continue;
            board[i][j]=k+'1';
            rowStat[i]|=1<<k;
            colStat[j]|=1<<k;
            sectionStat[i/3][j/3]|=1<<k;
            if(!fillup(board,num+1)){
                board[i][j]='.';
                rowStat[i]&=~(1<<k);
                colStat[j]&=~(1<<k);
                sectionStat[i/3][j/3]&=~(1<<k);
                continue;
            }
            else return 1;
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board){
        checkSudoku(board);
        fillup(board,0);
    }
};
