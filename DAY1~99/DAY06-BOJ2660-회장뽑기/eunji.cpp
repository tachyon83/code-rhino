#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define SORT(a,b) {if(a>b){int t=a;a=b;b=t;}}

using namespace std;
int arr[51][51];

void FW(int N) {
	//플로이드-와샬을 썼습니다(삼중포문)
	//v는 거치는 vertex
	//i는 시작점
	//j는 도착점
	//배열의 반만썼기때문에 저장, 조회시 작은 vertex를 시작vertex로 바꿔줍니다.
	for (int v = 1; v <= N; v++) {

		for (int i = 1; i <= N; i++) {

			if (i == v) continue;
			for (int j = i+1; j <= N; j++) {

				if (j == v) continue;;
				int tmp=v;

				if (tmp > j) {
					tmp = arr[i][tmp] + arr[j][tmp];
				}
				else if (tmp < i) {
					tmp = arr[tmp][i] + arr[tmp][j];
				}
				else {
					tmp = arr[i][tmp] + arr[tmp][j];
				}

				SORT(arr[i][j], tmp);

			}
		}
	}

}

int main() {
	//bfs, 플로이드 와샬로 풀수있다.
	//플로이드와샬로 풀어보자
	//무향 그래프 이므로 배열의 반은 쓰지않는다.
	int ver;
	int x, y;
	int count[51]={ 0, };

	fill(&arr[0][0], &arr[50][51], 999);
	cin >> ver;
	for (int i = 1; i <= ver; i++) {
		arr[i][i] = 0;
	}
	while (1) {
		cin >> x >> y;
		if (x == -1 && y == -1) {
			break;
		}
		SORT(x, y);
		arr[x][y] = 1;
	}

	//플로이드 넣기
	FW(ver);

	//출력할때 시간을 많이 낭비한거 같아요...
	//제일 큰거 찾고 그걸 저장해서...다시 그중에서 작은걸 벡터에 넣어서..ㅠㅠ
	for (int i = 1; i <= ver; i++) {
		int max = 0;
		for (int j = 1; j <= ver; j++) {
			int tmp;
			if (i == j) {
				continue;
			}
			tmp = (i > j ? arr[j][i] : arr[i][j]);
			max = (tmp > max ? tmp : max);
		}
		count[i] = max;
	}

	int least=50;
	for (int i = 1; i <= ver; i++) {
		if (count[i] < least) {
			least = count[i];
		}
	}

	vector<int> vec;
	for (int i = 1; i <= ver; i++) {
		if (least == count[i]) {
			vec.push_back(i);
		}
	}
	printf("%d %d\n", least, vec.size());
	for (int i = 0; i < vec.size(); i++) {
		printf("%d ",vec[i]);
	}


}
