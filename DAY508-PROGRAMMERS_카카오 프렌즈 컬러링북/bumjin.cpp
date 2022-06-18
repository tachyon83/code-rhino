#include <vector>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int visited[100][100];
int max_val;
int number_of_area;

int Bfs(int x,int y,int m,int n,int area_max,vector<vector<int>> Map){   
    printf("started\n");
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int color=Map[x][y];
    queue <pair<int,int>> q;
    q.push(make_pair(x,y));
    area_max++;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        visited[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ny>=0&&nx>=0&&nx<m&&ny<n&&visited[nx][ny]==false&&Map[nx][ny]==color){
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
                area_max++;
            }
        }        
    }
    printf("area_max %d\n",area_max);
 return area_max;  
  
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m,int n,vector<vector<int>> picture) {
    memset(visited,0,sizeof(visited));
    max_val=0;
    number_of_area = 0;
    int max_size_of_one_area = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0&&picture[i][j]!=0){
                max_size_of_one_area=Bfs(i,j,m,n,0,picture);
                number_of_area++;  
                 if(max_val<max_size_of_one_area){
                    max_val = max_size_of_one_area;
                }
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1]=max_val;
    return answer;
}
