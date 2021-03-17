//스도쿠
//https://www.acmicpc.net/problem/2580

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> v;

bool checkRow(int row, int num) { // 열에 같은 번호가 있는지 확인
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == num)
			return false;
	}
	return true;
}

bool checkCol(int col, int num) { // 행에 같은 번호가 있는지 확인
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == num)
			return false;
	}
	return true;
}

bool checkSquare(int row, int col, int num) { // 3 * 3칸 내에 같은 번호가 있는지 확인
	row /= 3;
	col /= 3;

	for (int i = row * 3; i < (row * 3) + 3; i++) {
		for (int j = col * 3; j < (col * 3) + 3; j++) {
			if (sudoku[i][j] == num)
				return false;
		}
	}
	return true;
}

bool check(int row, int col, int num) { 
	return checkRow(row, num) && checkCol(col, num) && checkSquare(row,col,num);
}

void DFS(int index) {
	if (index == v.size()) { // 빈칸을 다 채웠을때 결과 출력
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0); //한가지 경우만 알면되기때문에 강제 종료
	}
	
	for (int i = 1; i <= 9; i++) {
		int row = v[index].first;
		int col = v[index].second;
		if (check(row, col, i)) { //숫자가 들어갈수 있는지 확인
			sudoku[row][col] = i;
			DFS(index + 1);
			sudoku[row][col] = 0;
		}
	}
}

int main() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] == 0) //빈칸 저장
				v.push_back({ i,j });
		}
	}

	DFS(0);
	return 0;
}
