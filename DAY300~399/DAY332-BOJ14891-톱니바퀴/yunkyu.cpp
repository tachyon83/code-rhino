#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <cmath>
using namespace std;

vector<int> gear[4];
vector<pair<int, int>> turn;
bool diff[3]; // 0 1 , 1 2 , 2 3
bool turned[4];

void present() {
	diff[0] = diff[1] = diff[2] = false;

	if (gear[0][2] != gear[1][6]) {
		diff[0] = true;
	}
	if (gear[1][2] != gear[2][6]) {
		diff[1] = true;
	}
	if (gear[2][2] != gear[3][6]) {
		diff[2] = true;
	}
}
void turnGear(int g, int dir) {
	int i;
	if (dir == 1) {
		gear[g].insert(gear[g].begin(), gear[g][gear[g].size()-1]);
		gear[g].pop_back();
	}
	else {
		gear[g].push_back(gear[g][0]);
		gear[g].erase(gear[g].begin());
	}
}
void turningGear(int g, int dir) {
	if (turned[g] == false) {
		turnGear(g, dir);
		turned[g] = true;
	}
	else {
		return;
	}

	if (g == 0 && diff[0] == true) {
		turningGear(g + 1, -dir);
	}
	else if (g == 3 && diff[2] == true) {
		turningGear(g - 1, -dir);
	}
	else if(g == 2){
		if (diff[1] == true) turningGear(g - 1, -dir);
		if (diff[2] == true) turningGear(g + 1, -dir);
	}
	else if(g == 1){
		if (diff[0] == true) turningGear(g - 1, -dir);
		if (diff[1] == true) turningGear(g + 1, -dir);
	}
}
void driveGear() {
	int i;

	for (i = 0; i < turn.size(); i++) {
		memset(turned, false, sizeof(turned));
		present();
		int g = turn[i].first;
		int dir = turn[i].second;
		turningGear(g, dir);
	}
}
int main() {

	int i, j, n;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			int pole;
			scanf("%1d", &pole);
			gear[i].push_back(pole);
		}
	}
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int g, dir;
		scanf("%d %d", &g, &dir);
		turn.push_back(make_pair(g - 1, dir));
	}
	driveGear();
	int sum = 0;
	for (i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			sum += pow(2, i);
		}
	}
	printf("%d", sum);
	return 0;
}
