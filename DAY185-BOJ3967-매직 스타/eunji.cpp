#include<iostream>

using namespace std;
void writeNum(int turn, int magicstar[], bool visit[]);
void printMagicstar(int magic[]);
bool isPossible(int a, int b, int c, int d, int magic[]);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int magicstar[12] = { 0, };
	bool visit[13] = { 0, };

	int index = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			char x;
			cin >> x;
			if (x != '.') {
				if (x == 'x') index++;
				else {
					int num = x - 'A' + 1;
					magicstar[index] = num;
					visit[num] = true;
				}
			}
		}
	}

	writeNum(0, magicstar, visit);
}

void writeNum(int turn,int magicstar[],bool visit[]) {
	for (int i = turn; i < 12; i++) {
		if (!magicstar[i]) {
			for (int j = 1; j <= 12; j++) {
				if (!visit[j]) {
					magicstar[i] = j;
					visit[j] = true;
					writeNum(i + 1,magicstar,visit);
					visit[j] = false;
					magicstar[i] = 0;
				}
			}
		}
	}
	if(!isPossible(0, 2, 5, 7, magicstar)) return;
	if (!isPossible(7, 8, 9, 10,magicstar)) return;
	if (!isPossible(0, 3, 6, 10, magicstar)) return;
	if (!isPossible(1, 2, 3, 4, magicstar)) return;
	if (!isPossible(4, 6, 9, 11, magicstar)) return;
	if (!isPossible(1, 5, 8, 11, magicstar)) return;
	printMagicstar(magicstar);

}

void printMagicstar(int magic[]) {
	for (int i = 0; i < 12; i++) {
		printf("%c ", magic[i] + 'A' - 1);
	}
	exit(0);
}

bool isPossible(int a, int b, int c, int d, int magic[]){
	if (magic[a] + magic[b] + magic[c] + magic[d]==26) return true;
	else return false;
}
