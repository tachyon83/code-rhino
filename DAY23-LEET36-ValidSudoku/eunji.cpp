bool check[9] = { false, };
	for (int i = 0; i < 9; i++) {
		memset(check, false, sizeof(check));
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				if (check[board[i][j] - '1']) {
					return false;
				}
				else {
					check[board[i][j] - '1'] = true;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		memset(check, false, sizeof(check));
		for (int j = 0; j < 9; j++) {
			if (board[j][i] != '.') {
				if (check[board[j][i] - '1']) {
					return false;
				}
				else {
					check[board[j][i] - '1'] = true;
				}
			}
		}
	}

	for (int block = 0; block < 9; block++) {
		memset(check, false, sizeof(check));
		for (int i=block%3*3; i<block%3*3+3; i++) {
			for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
				if (board[i][j] != '.') {
					if (check[board[i][j] - '1']) {
						return false;
					}
					else {
						check[board[i][j] - '1'] = true;
					}
				}
			}

		}
	}
	return true;
