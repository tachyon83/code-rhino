#include <iostream>
#include <bitset>

using namespace std;

//메모리 제한때문에 지역변수로 넣으면 오류나는건가...
int num;
bitset<1 << 25> bits;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		cin >> num;

		// 종료조건
		if (cin.eof() == true) {
			break;
		}

		// test: 비트상태
		// set: 비트켜기
		// num에 대한 bit상태가 false라면 true로 변경해주고 출력
		if (!bits.test(num)) {
			bits.set(num);
			cout << num << ' ';
		}
	}

	return 0;
}
