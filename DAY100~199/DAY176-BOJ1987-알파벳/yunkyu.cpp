//알파벳
//https://www.acmicpc.net/problem/1987

#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int maxL = 0;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
char board[20][20];
bool visited[26]; //아스키 코드 이용해서 알파벳 저장 ex) A는 정수로 65이므로 A를 빼주면 0번째 index

inline int alphabet(char x) {  //알파벳의 index를 구함
	return (int)x - 'A';
}
void DFS(int y, int x, int cnt) { 
	visited[alphabet(board[y][x])] = true;
	int i;

	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < R && 0 <= nx && nx < C) {
			if (!visited[alphabet(board[ny][nx])]) { //방문한 알파벳이 아니라면
				DFS(ny, nx, cnt + 1);
				visited[alphabet(board[ny][nx])] = false; //방문하기 전으로 돌려준다
			}
		}
	}

	if (maxL < cnt) maxL = cnt; //최대 칸수 구함
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	DFS(0, 0, 1);

	printf("%d", maxL);
	return 0;
}
