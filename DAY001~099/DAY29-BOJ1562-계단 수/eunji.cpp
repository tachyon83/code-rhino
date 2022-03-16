#include <iostream>
#include <stdio.h>
#include <memory.h>
#define MOD 1000000000
#define ALL 1024
using namespace std;

//쉬운 계단수와 달리 0~9까지 모두 등장해야된다 --> dp를 돌리면서도 지금까지 어떤수가 등장하였는지 표시를 해야된다 --> 비트마스킹으로 표시해본다(2^10 -1)로 표현가능)
//쉬운계단수 문제의 arr[길이][마지막수]에서 arr[길이][마지막수][비트로 쓴수]로 바꾸면 될거같다

//숫자표시를 0부터 해야되니까 000..001  이 숫자0을 나타내고 000..010  이 숫자 1을 나타냄 (헷깔림 주의)
//참고하기 좋은 사이트!
//https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=221130521559&proxyReferer=https:%2F%2Fwww.google.com%2F

int main() {
	int N;
	cin >> N;

	//3차원 배열 동적할당은 처음 써보는거 같다
	long long *** arr = (long long ***)malloc(sizeof(long long **)*(N + 1));
	for (int i = 0; i <= N; i++) {
		arr[i] = (long long **)malloc(sizeof(long long*) * 10);
		for (int j = 0; j < 10; j++) {
			arr[i][j] = (long long*)calloc(ALL, sizeof(long long));
		}

	}

	//길이 1일때 --> 0은 없음(1~9)
	for (int i = 1; i <= 9; i++) {
		arr[1][i][1 << i] = 1;
	}

	// i=길이
	for (int i = 2; i <= N; i++) {

		// j=마지막수
		for (int j = 0; j <= 9; j++) {

			// visit=방문상태
			//이미썼던 수를 써도된다는것을 주의하자! --> 마지막에 출력할때만 모두 방문한것만 출력하면되니까
			//방문할 수를 쓴것 + 방문할 수를 안쓴것
			for (int visit = 1; visit < ALL; visit++) {

				//j가 visit에 방문한한걸로 되어잇으면 잘못된것
				if (!((1<<j) & visit)) {
					continue;
				}

				int notVisitBefore = visit;
				notVisitBefore &= ~(1 << j);

				if (j == 0) {
					arr[i][j][visit] = (arr[i - 1][1][visit] + arr[i - 1][1][notVisitBefore]) % MOD;
				}
				else if (j == 9) {
					arr[i][j][visit] = (arr[i - 1][8][visit] + arr[i - 1][8][notVisitBefore]) % MOD;
				}
				else {
					arr[i][j][visit] = ((arr[i - 1][j - 1][visit] + arr[i - 1][j - 1][notVisitBefore]) % MOD + (arr[i - 1][j + 1][visit] + arr[i - 1][j + 1][notVisitBefore]) % MOD) % MOD;
				}
			}

		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + arr[N][i][ALL - 1]) % MOD;
	}
	cout << sum;


}
