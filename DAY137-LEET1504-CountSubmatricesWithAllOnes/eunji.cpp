int numSubmat(vector<vector<int>>& mat) {
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int>> arr(n,vector<int>(m));

	//연결되어 사각형되는거 갯수등록(한줄씩)
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (!mat[i][j]) tmp = 0;
			else tmp++;
			arr[i][j] = tmp;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = 987654321;
			for (int k = i; k < n; k++) {
				if(arr[k][j] < tmp) tmp = arr[k][j];
				sum += tmp;
			}
		}
	}
	return sum;
}
