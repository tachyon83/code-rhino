//미완성
#include <iostream>
#include <vector>

using namespace std;

void ValidSudoku(vector<vector<char>>& board);
//손으로직접 스도쿠를 풀때처럼?? 알고리즘을 짜보앗다.
//굉장히 비효율적이게 풀었다.
int main() {
	vector<vector<char> > board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},{'6', '.', '.', '1', '9', '5', '.', '.', '.'},{'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},{'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},{'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},{'.', '.', '.', '.', '8', '.', '.', '7', '9'};

	ValidSudoku(board);


	}


		void ValidSudoku(vector<vector<char>>& board) {
		int row[9][9];
		int col[9][9];
		int block[9][9];

		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));

		//있는 수를 표시한다.
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') row[i][board[i][j] - '1'] = 1;
				if (board[j][i] != '.') col[i][board[j][i] - '1'] = 1;
			}
		}

		for (int blo = 0; blo < 9; blo++) {
			for (int i = blo % 3 * 3; i < blo % 3 * 3 + 3; i++) {
				for (int j = blo / 3 * 3; j < blo / 3 * 3 + 3; j++)
					if (board[i][j] != '.')  block[blo][board[i][j] - '1'] = 1;
			}
		}

		//없는수 대입->만약 중복이 발견되면 backtracking
		}
