#include <iostream>
#include <string>
using namespace std;

int s = 0;

void execute(string comm) { 
	int el;
	if (comm == "add") { // OR연산으로 비트 틈
		cin >> el;
		s |= (1 << el);
	}
	else if (comm == "remove") { // AND와 NOT 연산으로 비트 꺼줌
		cin >> el;
		s &= ~(1 << el);
	}
	else if (comm == "check") { //AND연산으로 비트가 켜져있는지 확인
		cin >> el;
		if ((s & (1 << el))) {
			cout << 1 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	else if (comm == "toggle") { //XOR연산으로 켜있으면 끄고 꺼있으면 켜기
		cin >> el;
		s ^= (1 << el);
	}
	else if (comm == "all") //s에 대해 NOT연산 후 OR연산시 모두 1이 됨
		s |= ~s;
	else if (comm == "empty") //0은 공집합
		s = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string comm;
		cin >> comm;
		execute(comm);
	}

	return 0;
}
