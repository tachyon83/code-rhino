//원래는 위상정렬로 할려햇는데 복잡해서 그냥 막무가내 전탐으로 풀엇습니다...
//너무 더럽게짜서..코드보지마세요 ㅠㅠ

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
int findMax(int index);
int findMin(int index);

vector <char> arr;
vector<bool> number;
vector<int> answer;
int N;

int main() {

	char x;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		number.push_back(false);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 9; i >=0; i--) {
		answer.push_back(i);
		number[i] = true;
		if (findMax(0)) {
			for (int i = 0; i <=N; i++) {
				int x = answer.back();
				answer.pop_back();
				number[x] = false;
			}
			break;
		}
	}
	

	for (int i = 0; i <= 9; i++) {
		answer.push_back(i);
		number[i] = true;
		if (findMin(0)) {
			break;
		}
	}
}

int findMax(int index) {
	if (index == N) {
		for (int i = 0; i <= N; i++) {
			cout<<to_string(answer[i]);
		}
		printf("\n");
		return 1;
	}
	if (arr[index] == '<') {
		for (int i = 9; i > answer[index]; i--)  {
			if (number[i] == false) {
				answer.push_back(i);
				number[i] = true;
				if (findMax(index + 1)) {
					return 1;
				}

			}
		}
	}
	else {
		for (int i = (answer[index] - 1); i >= 0; i--) {
			if (number[i] == false) {
				answer.push_back(i);
				number[i]=true;
				if (findMax(index + 1)) {
					return 1;
				}
			}
		}
	}
	int k = answer.back();
	number[k] = false;
	answer.pop_back();
	return 0;
}

int findMin(int index) {
	if (index == N) {
		for (int i = 0; i <= N; i++) {
			cout << to_string(answer[i]);
		}
		return 1;
	}
	if (arr[index] == '<') {
		for (int i = (answer[index]+1); i <= 9; i++) {
			if (number[i] == false) {
				answer.push_back(i);
				number[i] = true;
				if (findMin(index + 1)) {
					return 1;
				}

			}
		}
	}
	else {
		for (int i = 0; i < answer[index]; i++) {
			if (number[i] == false) {
				answer.push_back(i);
				number[i] = true;
				if (findMin(index + 1)) {
					return 1;
				}
			}
		}
	}
	int k = answer.back();
	number[k] = false;
	answer.pop_back();
	return 0;
}
