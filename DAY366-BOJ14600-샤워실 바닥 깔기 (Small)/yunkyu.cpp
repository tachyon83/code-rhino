#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[5][5];
int cnt = 0;

void setTile(int x, int y, int leftX, int rightX, int topY, int bottomY, int l) {
	if (l == 2) { // 변의 길이가 2일때 타일 배치
		++cnt;
		if (leftX <= x && x <= rightX && topY <= y && y <= bottomY) { // 범위안에 배수구가 존재한다면
			for (int i = topY; i <= bottomY; i++) {
				for (int j = leftX; j <= rightX; j++) {
					if (i == y && j == x) {
						arr[i][j] = -1;
					}
					else arr[i][j] = cnt;
				}
			}
		}
		else { // 배수구가 존재하지 않는다면 가장자리에 타일을 붙여서 배치
			for (int i = topY; i <= bottomY; i++) {
				for (int j = leftX; j <= rightX; j++) {
					if (i == 1 || j == 1 || i == 4 || j == 4) {
						arr[i][j] = cnt;
					}
				}
			}
		}

		return;
	}
	else { 
		int midX = (leftX + rightX) / 2;
		int midY = (topY + bottomY) / 2;
		// 바닥을 4등분
		setTile(x, y, leftX, midX, topY, midY, l / 2);
		setTile(x, y, leftX, midX, midY + 1, bottomY, l / 2);
		setTile(x, y, midX + 1, rightX, topY, midY, l / 2);
		setTile(x, y, midX + 1, rightX, midY + 1, bottomY, l / 2);
	}
}

int main() {
	int k, x, y;
	scanf("%d", &k);
	scanf("%d %d", &x, &y);

	if (k == 1) { // 한 변의 길이가 2
		// 배수구가 있는 위치는 -1 나머지는 1로 출력
		for (int i = 2; i >= 1; i--) {
			for (int j = 1; j <= 2; j++) {
				if (i == y && j == x) {
					printf("-1 ");
				}
				else
					printf("1 ");
			}
			printf("\n");
		}
	}
	else { // 한 변의 길이가 4
		setTile(x, y, 1, 4, 1, 4, 4);
		++cnt;
		// 가장자리 변을 제외한 안쪽에 타일을 배치
		for (int i = 2; i <= 3; i++) {
			for (int j = 2; j <= 3; j++) {
				if (arr[i][j] == 0) arr[i][j] = cnt;
			}
		}

		for (int i = 4; i >= 1; i--) {
			for (int j = 1; j <= 4; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
