//수정중
#include <iostream>
#include <vector>
using namespace std;
int putDough(vector<int> oven, vector<int>dough, int D, int N);
int realFunc(int D, int N);
int count(int last,int N,int D);

vector<int> oven;
vector<int> dough;

int main() {
	int D, N;
	cin >> D >> N;

	for (int i = 0; i < D; i++) {
		int tmp;
		cin >> tmp;
		oven.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		dough.push_back(tmp);
	}
	//cout << putDough(oven, dough, D, N);
	cout << realFunc(D, N);
}

//그냥푸니 시간초과
int putDough(vector<int> oven, vector<int>dough, int D, int N) {
	int top = D - 1;
	for (int j = 0; j < N; j++) {
		if (j==0 || dough[j] > dough[j-1]) {
			for (int i = 0; i < D; i++) {
				if (top == i || oven[i] < dough[j]) {
					top = i - 1;
					break;
				}
			}
		}
		else top--;

	}
	if (top < 0) return 0;
	else return top+1;
}
//이분탐색
int realFunc(int D, int N) {
	int i = 0;
	while (dough[N - 1] >= oven[i++]);
	int end = i - 1;
	int start = 0;
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (count(mid,N,D) <= N-1) end = mid;
		else start = mid+1;
	}
	return mid+1;

}
int count(int last,int N,int D) {
	int j = D-1;
	int num = 0;
	for (int i = 0; i < N - 1; i++) {
		if (dough[i] <= oven[j--]) num++;
		if (j == last) break;
	}
	return num;
}
