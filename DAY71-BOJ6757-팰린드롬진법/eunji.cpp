//6757_팰린드롬진법
#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

bool isPalindrome(int x, int notat,double lognum);

int main() {
	int X;
	cin >> X;
	double lognum = log10(double(X));
	for (int i = 2; i < X; i++) {
		if (isPalindrome(X,i,lognum)) cout << i <<endl;
	}
}

//팰린드롬인지 판별하는 함수

//첨엔 원하는 진법으로 바꾼 후에 다시 배열의 반만큼 조사하여 대칭인지 판별하였으나,
//시간초과가 나서-> X진법으로 바꾸면서 조사하는 방법을 생각하였다.
//바꾸면서 조사할려면 언제 바꾼 진법 길이의 반이 되는지 알아야한다- 이를 위해 최고차항이 x진법의 몇승까지 있는지 알아야하고,
//이를 위해 log함수를 이용하였다.
//근데도 시간초과가 나서->대칭수를 찾지말고 대칭수를 만들어가야겠다 생각하였다.
//아직 시도중..ㅠ도와주세영...

bool isPalindrome(int origin,int notat,double lognum) {
	vector<int> nums;
	int num = origin;
	int po = (int)(lognum / log10(double(notat)));
	for (int i = 0; i < (po + 1) / 2; i++) {
		nums.push_back(num % notat);
		num /= notat;
	}
	int numsize = nums.size();
	//홀수개일땐 한번더 나눠야됨
	if (po % 2 == 0) {
		num /= notat;
	}
	while (num > 0) {
		if (num % notat != nums[--numsize]) return false;
		num /= notat;
	}

	return true;
}
