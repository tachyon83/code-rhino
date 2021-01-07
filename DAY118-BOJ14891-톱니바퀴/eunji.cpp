#include <stdio.h>
#include <cmath>
using namespace std;
typedef struct Gear {
	int tooth[8];
	int left;
	int right;
}Gear;
Gear gear[4];
void rotate(int target, int dir);
void change(int target, int dir);
int knowSum();

int main() {

	//톱니초기화
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%1d", &gear[i].tooth[j]);
		}
		gear[i].right = 2;
		gear[i].left = 6;
	}
	int turn;
	scanf_s("%d", &turn);
	for (int i = 0; i < turn; i++) {
		int num, dir;
		scanf_s("%d %d", &num, &dir);
		rotate(num-1, dir);
	}

	printf("%d", knowSum());
}

void rotate(int target, int dir) {

	int left = gear[target].tooth[gear[target].left];
	int right= gear[target].tooth[gear[target].right];
	int leftdir, rightdir;
	leftdir = rightdir = dir;
	change(target,dir);
	for (int i = target-1; i>=0; i--) {
		if (left == gear[i].tooth[gear[i].right]) break;
		left= gear[i].tooth[gear[i].left];
		leftdir*=(-1);
		change(i,leftdir);

	}
	for (int i = target + 1; i < 4; i++) {
		if (right == gear[i].tooth[gear[i].left]) break;
		right = gear[i].tooth[gear[i].right];
		rightdir *= (-1);
		change(i,rightdir);

	}
}
void change(int target,int dir) {
	if (dir == 1) {
		gear[target].right= (gear[target].right + 7) % 8;
		gear[target].left = (gear[target].left + 7) % 8;
	}
	else {
		gear[target].right = (gear[target].right + 1) % 8;
		gear[target].left = (gear[target].left + 1) % 8;
	}
}
int knowSum() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i].tooth[((gear[i].left)+2)%8] == 1) {
			sum += pow(2.0, i);
		}
	}
	return sum;
}
