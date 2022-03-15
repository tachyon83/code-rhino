#include <iostream>
#include <queue>
using namespace std;

//입력 1,2 데이터
int n,m;
//입력 데이터
int map[100][100];
//방문 배열선언
bool visited[100][100]={0,};
//상하좌우(0,1)(1,0)(-1,0)(0,-1)
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
//큐
queue< pair<int, int>> q;
int first,second;
int cnt=0;

void input(){
    cin >>n;
    cin >>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              cin>>map[i][j];
        }          
    }
}

void solution(){
    q.push({0,0});//첫번쨰 입력

    while((q.empty()!=true)){
        //큐에서 pop시킴
        first=q.pop.first();    
        second=q.pop.second();

        //방문처리
        visited[first][second]=1;
        //큐에서 pop시킨 데이터 사방으로 탐색
        for(int k=0;k<4;k++){
            
        }
        //만약 0이 아니고 방문하지 않았다면 개수만큼  뺴줌

        //사방 탐색한 것중 0이 아닌것 큐에 넣어줌


    }
    //주변 숫자가 없다면 숫자증가 
    cnt++;
}



int main(){
    input();
    solution();
    if (cnt>0){
        printf("answer is %d\n",cnt);

    }
    return 0;
}
