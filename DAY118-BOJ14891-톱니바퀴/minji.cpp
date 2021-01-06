#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int gear[4][8] = {0};
int dirs[2] = {-1, 1};
int k;

int ans(){
	int answer = 0;
	for (int i = 0; i<4; i++)
		answer += (gear[i][0] == 1 ? pow(2, i) : 0);

	return answer;
}

void res_gear_num(int rotate_gear, int rotate_dir) {
	if (rotate_dir == 1) {
		int sub = gear[rotate_gear][7];
		for (int i = 7; i> 0; i--) {
			gear[rotate_gear][i] = gear[rotate_gear][i-1];
		}
		gear[rotate_gear][0] = sub;
	}
	else if (rotate_dir == -1) {
		int sub = gear[rotate_gear][0];
		for (int i = 1; i < 8; i++) {
			gear[rotate_gear][i-1] = gear[rotate_gear][i];
		}
		gear[rotate_gear][7] = sub;
	}
}

void rotate_gear(int rotate_gear, int rotate_dir) {
	int rotateDir[4] = {0, 0, 0, 0};
	rotateDir[rotate_gear] = rotate_dir;

	queue<pair<int, int>> find_queue;

    int start = rotate_gear;
    for (int i = 0; i < 2; i++) {
        int next = start + dirs[i];
        if ( (next >= 0) && (next < 4) && (rotateDir[next] == 0) && (rotateDir[start] != 0) )
            find_queue.push(pair<int, int> (start, next));
	}
 

	while (find_queue.size()) {
		pair<int, int> move_pair = find_queue.front();
		find_queue.pop();

		int left = (move_pair.first < move_pair.second ? move_pair.first : move_pair.second);
		int right = (move_pair.first < move_pair.second ? move_pair.second : move_pair.first);    
		
		if  (gear[left][2] == gear[right][6]) continue;

		rotateDir[move_pair.second] = -(rotateDir[move_pair.first]);

		int start = move_pair.second;
		for (int i = 0; i < 2; i++) {
			int next = start + dirs[i];
			if ((next >= 0) && (next < 4) && (rotateDir[next] == 0) && (rotateDir[start] != 0))
				find_queue.push(pair<int, int> (start, next));
		}
	}

	for (int i = 0; i< 4; i++){
		res_gear_num(i, rotateDir[i]);
	}
}

int main() {
	//초기화
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int gear_num, dir;
		cin >> gear_num >>dir;

		rotate_gear(gear_num - 1, dir);
	}

	cout << ans();
	return 0;
}
