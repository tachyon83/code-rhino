#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

int N, d, k, c;
int flag, cnt, coupon, maxi = 0;
int sushi[300001];
int check[3001];
vector<int> eat;

int main()
{
	// N:접시수 d:초밥종류수 k:연속접시 C:쿠폰번호
	cin >> N >> d >> k >> c;
	
	// 회전벨트 위 초밥
	for (int i = 0; i < N; i++) cin >> sushi[i];

	// 슬라이딩 윈도우
	for (int i = 0; i < N; i++)
	{
		flag = 0; // 중복된 스시 체크
		coupon = 1; // 쿠폰 스시가 있는지 확인
		for (int j = i; j < i + k; j++) 
		{				
			if (check[sushi[j % N]] == 1) flag++; // 이미 먹은 초밥일 경우 중복 수 표시	
			else check[sushi[j % N]] = 1; // 처음 먹어보는 초밥일 경우 체크		

			if (sushi[j % N] == c) coupon = 0; // 쿠폰 스시 있을 시
		}

		maxi = max(maxi, k - flag + coupon); //연속으로 먹을 수 있는 최대접시 - 중복접시 + 쿠폰스시	
		memset(check, 0, sizeof(check)); // 체크 초기화
	}

	cout << maxi;
}
