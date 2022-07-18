#include <string>
#include <vector>
#include <iostream>
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
using namespace std;

vector<int> answer(5, 1);
vector<string>place;
vector<pair<int, int>>loc;
vector<vector<bool>>visit;
int cnt(0);

void DFS(int y, int x) {    
    visit[y][x] = true;
    int idx(0);
    int n_y(0), n_x(0);    
    char ch(' ');
    for (idx = 0; idx < 4; ++idx) {
        n_y = y + dy[idx];
        n_x = x + dx[idx];        
        if (n_y >= 0 && n_y < 5 && n_x >= 0 && n_x < 5) {
            if (visit[n_y][n_x]) continue;
            ch = place[n_y][n_x];
            if (ch == 'X' || (place[y][x] == 'O' && ch=='O'))
                continue;
            else if (ch == 'P') {                
                answer[cnt] = 0;
                break;
            }            
            else if (ch == 'O') {                
                DFS(n_y, n_x);
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    int y(0), x(0);
    int idx(0), idx2(0);
    for (idx = 0; idx < 5; ++idx) {
        loc = vector<pair<int, int>>();        
        for (y = 0; y < 5; ++y) {
            for (x = 0; x < 5; ++x) {
                if (places[idx][y][x] == 'P') {                    
                    loc.push_back({ y,x });
                }
            }
        }
        visit = vector<vector<bool>>(5,vector<bool>(5,false));
        place = vector<string>(places[idx]);
        for (idx2 = 0; idx2 < loc.size(); ++idx2) {                               
            DFS(loc[idx2].first, loc[idx2].second);            
            if (answer[cnt] == 0) break;            
        }                
        ++cnt;
    }

    return answer;
}
