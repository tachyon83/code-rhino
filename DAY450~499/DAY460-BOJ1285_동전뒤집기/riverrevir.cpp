#include <bits/stdc++.h>

using namespace std;
string inp;
int n, res=9999999;
int board[21][21];
int power(int n) {
	int ret = 1;
	for(int i = 0; i < n; i++) ret *= 2;
	return ret;
}
int main(void) {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> inp;
		for(int j = 0; j < inp.size(); j++) {
			if(inp[j] == 'T') board[i][j+1]=1;
		}
	}
	
	for(int i = 0; i < (1<<n); i++) {
		int copy_board[21][21];
		for(int j = 1; j <= n; j++) 
			for(int k = 1; k <= n; k++) copy_board[j][k] = board[j][k];
		
		for(int j = 0; j < n; j++) {
			int next = power(j); 
			if((next&i) != 0) {
				for(int k = 1; k <= n; k++) {
					if(copy_board[j][k] == 0) copy_board[j][k]=1;
					else copy_board[j][k]=0;
				}
			}
		}
		
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			int tmp_cnt = 0, rev_tmp_cnt = 0;
			for(int k = 1; k <= n; k++) {
				if(copy_board[k][j]) tmp_cnt++;
				else rev_tmp_cnt++;
			}
			cnt+=(min(rev_tmp_cnt, tmp_cnt));
		}
		res = min(res, cnt);
	}
	
	cout << res << endl;
	return 0;
}
