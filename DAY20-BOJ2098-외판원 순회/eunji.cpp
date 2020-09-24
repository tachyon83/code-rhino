//수정완료!
#include <iostream>
#include <algorithm>
#include <memory.h>
#define MIN(a,b)(a<=b?a:b)
#define MAX 9999999999;

using namespace std;
int dp[16][65536];
int city[16][16];
int N;

int TSP(int now, int set);

//TSP 문제

//어차피 시작점으로 돌아오므로, 어디서 시작하든 결과값은 같다.
//도시를 비트로 표현하면 연산도 쉽고, 메모리도 줄일수 있다
//dp를 이용하여 DFS로 풀었을때의 중복 연산 시간을 줄인다.

//dp[현재위치][지금까지 지나온점(집합을 비트로 표현)] -> 이상태에서 남은 경로를 최소로 돌때의 값을 나타냄
//0011-> 0번,1번 지난거
//0101-> 0번,2번 지난거

//도시가 최대 16개라면 1111111111111111 -> 2^16 -> 65535(10진수) -> unsigned short로 표현가능 -> 그냥 편하게 int씀!

//비트 연산 공부를 처음해서 그부분에서 시간이 많이 잡아먹었네요...
int main() {
	memset(city, 0, sizeof(city));
	memset(dp, 0, sizeof(dp));

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//i에서 j로의 비용 저장
			cin >> city[i][j];
		}
	}

	cout << TSP(0, 1);

}

int TSP(int now, int set) {

	//이미 다 방문을 한 상태면(set이 111111....11), 시작지점(0번)으로 돌아가는 값만 남음
	if (set == ((1 << N) - 1)) {
		if (city[now][0]==0) {
			return MAX;
		}
		return city[now][0];
	}
	//이미 찾아놓은 값이면 계산할 필요없음
	else if (dp[now][set] != 0) {
		return dp[now][set];
	}

	//아직 모르는 값이면..,
	else {
		int min = MAX;

		for (int next = 0; next < N; next++) {

			//next는 이미갔던곳(set)에 없는 값이어야함
			if ((set&(1 << next)) || city[now][next]==0) {
				continue;
			}
			else {
				min = MIN(min, TSP(next, set | (1 << next)) + city[now][next]);
			}
		}

		dp[now][set] = min;
		return dp[now][set];
	}

}
