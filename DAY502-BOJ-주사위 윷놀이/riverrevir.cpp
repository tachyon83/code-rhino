#include<iostream>
using namespace std;
 
// 주사위
int arr[10];
// 현재 말의 위치
int mal[4];
 
// 윷놀이 판
int map[35];
// - 판에서 방향 전환
int turn[35];
// - 현 위치에 말이 있는지 확인
bool check[35];
// - 윷놀이 판의 점수
int score[35];
 
// 최종 값
int ans = 0;
 
void dfs(int cnt, int sum) {
    if (cnt == 10) {
        //실행 할 곳
        if (sum > ans) ans = sum;
 
        return;
    }
    for (int i = 0; i < 4; i++) {
        // 현재 말 위치, 이동 할 말 위치
        int prev = mal[i];
        int now = prev;
        // 움직여야 하는 횟수
        int move = arr[cnt];
 
        // 만약 현재 위치가 방향 전환 해야하는 곳 이라면..
        if (turn[now] > 0) {
            now = turn[now];
            move -= 1;
        }
        // 주사위 만큼 이동
        while (move--) {
            now = map[now];
        }
 
        if (now != 21 && check[now] == true) continue;
 
        check[prev] = false;
        check[now] = true;
        mal[i] = now;
        
        dfs(cnt + 1, sum + score[now]);
 
        mal[i] = prev;
        check[prev] = true;
        check[now] = false;
    }
}
출처: https://haejun0317.tistory.com/163 [안산학생의 찬란한 개발:티스토리]
