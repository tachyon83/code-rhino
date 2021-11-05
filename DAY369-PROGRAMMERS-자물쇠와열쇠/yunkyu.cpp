// 테스트 케이스 15 실패
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n,m;
vector<pair<int,int>> hole;

void rotateKey(vector<vector<int>> &key){ // key를 90도로 회전
    vector<vector<int>> tmp = vector<vector<int>>(m,vector<int>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(key[i][j] == 1){
                tmp[m - j - 1][i] = key[i][j];
            }
        }
    }
    
    key = tmp;
}

bool unlock(int y,int x, vector<vector<int>> arr,vector<vector<int>> key) {
    // (y,x)를 시작점으로 key를 놓는다
    for(int i = y; i < y + m; i++){
        for(int j = x; j < x + m; j++){
            if(key[i - y][j - x] == 0) continue; // key의 홈부분은 무시
            if(arr[i][j] == 1) return false; // key의 돌기부분과 lock의 돌기부분이 만나면 false
            arr[i][j] = key[i - y][j - x];
        }
    }
        
    // lock에 홈부분이 비어있는지 확인한다
    for(int i = 0; i < hole.size(); i++){
        y = hole[i].first;
        x = hole[i].second;
        if(arr[y][x] == 0){
            return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n = lock.size();
    m = key.size();
    
    int l = 2 * m + n -2; // lock주위로 key를 최소한으로 겹치게 두었을때 가로세로의 최대 길이 
    
    vector<vector<int>> arr(l,vector<int>(l));
    
    // arr의 중간에 lock 위치시킴
    for(int i = m - 1; i < m + n - 1; i++){
        for(int j = m - 1 ; j < m + n - 1; j++){
            arr[i][j] = lock[i - m + 1][j - m + 1];
            if(arr[i][j] == 0) hole.push_back({i,j});
        }
    }
    
    for(auto h : hole){
        cout << h.first << h.second << endl;
    }
    
    for(int i = 0; i < 4; i++){
        for(int i = 0; i < l - m; i++) {
            for(int j = 0; j < l - m; j++){
                if(unlock(i,j,arr,key)) {
                    answer = true;
                    break;
                }
            }
        }
        rotateKey(key);
    }
    
    return answer;
}
