//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void goPrint();
void backPrint();

int map[1001][1001];
int go[1001];
int back[1001];
int n, m, x;

int main() {
	scanf("%d %d %d", &n, &m, &x);
	
	memset(map, 1000001, sizeof(map));
	memset(go, 0, sizeof(go));
	memset(back, 0, sizeof(back));

	for (int i = 0; i < m; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		map[s][e] = w;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {map[i][j] = 0;}
			else {continue;}
		}
	}


	//go & back reset
	for (int i = 1; i <= n; i++) {
		 go[i] = map[x][i]; 
		 back[i] = map[i][x];
	}

	goPrint();
	backPrint();

	//go
	
	for (int i = 1; i <= n; i++) {
			if ( i==x ) { continue; }
			for (int k = 1; k <= n; k++) {
				if (map[x][i] > map[x][k] + map[k][i] && map[x][k] + map[k][i] > 0) {
					map[x][i] = map[x][k] + map[k][i];
					go[i] = map[x][i];
					
				}
			}

			goPrint();
			
	}
	
	
	
	//back
	for (int i = 1; i <= n; i++) {
		
			if (i == x)  { continue; }
			for (int k = 1; k <= n; k++) {
				if (map[i][x] > map[i][k] + map[k][x]) {

					map[i][x] = map[i][k] + map[k][x];

					back[i] = map[i][x];
					
				}

			}
			backPrint();
	}
	
	int max = go[1] + back[1];
	for (int i = 2; i <= n; i++) {
		if (max < go[i] + back[i]) {
			max = go[i] + back[i];
		}
		printf("i = %d , max = %d\n", i, max);
	}

	printf("%d", max);
}


void goPrint() {
	//go print
	printf("\ngo print start\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", go[i]);
	}printf("\n\n");

}


void backPrint() {
	//go print
	printf("\nback print start\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", back[i]);
	}printf("\n\n");
}

