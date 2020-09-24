//학창시절에 위닝트리를 배워서 쉽게 풀수잇었다. (오랜만에 봐서 반가운 문제였다 ㅎㅎ)
//그려보았을때, 홀수일때는 항상 상근이가 이기고, 짝수일땐 창영이가 이겼다. (자기턴에서 무조건 자기가이기는 쪽으로 돌을 가지고 간다고 가정하였을때)

#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

}
