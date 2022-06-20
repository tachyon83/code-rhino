#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int arr[101][101];
bool check[101][101];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int xx,yy;
int area;
void bfs(int y,int x,int p){
    queue<pair<int,int>> qu;
    int temp_area=1;
    qu.push({y,x});
    check[y][x]=true;
    while(!qu.empty()){
        int oy=qu.front().first;
        int ox=qu.front().second;
        qu.pop();
        for(int i=0;i<4;i++){
            int ny=oy+dy[i];
            int nx=ox+dx[i];
            if(ny<0||ny>=yy||nx<0||nx>=xx) continue;
            if(!check[ny][nx]&&arr[ny][nx]==p){
                check[ny][nx]=true;
                temp_area++;
                qu.push({ny,nx});
            }
        }
    }
     
    if(area<temp_area){
        area=temp_area;
    }    
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    yy=m;
    xx=n;
    area=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=picture[i][j];
            check[i][j]=false;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]&&picture[i][j]!=0){
                bfs(i,j,picture[i][j]);
                number_of_area++;
            }
        }
    }
    max_size_of_one_area=area;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
