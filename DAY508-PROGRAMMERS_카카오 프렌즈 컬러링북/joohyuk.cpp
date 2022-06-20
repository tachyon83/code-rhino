#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    const int sz=100;
    bool visited[sz][sz];
    for(int i=0;i<m;++i)fill(visited[i],visited[i]+n,0);

    int dr[4]={0,1,0,-1},dc[4]={-1,0,1,0};
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    queue<pair<int,int>>q;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(!visited[i][j] && picture[i][j]){
                number_of_area++;
                q.emplace(i,j);
                visited[i][j]=1;
                int cnt=1;
                int cc=picture[i][j];
                
                while(!q.empty()){
                    auto curr=q.front();
                    q.pop();
                    for(int k=0;k<4;++k){
                        int nr=curr.first+dr[k];
                        int nc=curr.second+dc[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && picture[nr][nc]==cc){
                            cnt++;
                            visited[nr][nc]=1;
                            q.emplace(nr,nc);
                        }
                    }
                }
                max_size_of_one_area=max(max_size_of_one_area,cnt);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
