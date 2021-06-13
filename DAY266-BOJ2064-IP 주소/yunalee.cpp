#include <iostream>

using namespace std;

int ip[1001];

// 어렵다..ㅠㅠ
// 서브넷마스트 & ip주소 = 네트워크주소

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			int ipTmp;
			cin >> ipTmp;
			ip[i] <<= 8;
			ip[i] |= ipTmp;

			getchar();
		}
	}

	int subnet = 0;

	for (int i = 31; i >= 0; i--) {
		int bit = 1 << i;
		bool end = 0;
		
		for (int j = 1; j < N; j++) {
			if ((ip[0] & bit) != (ip[j] & bit)) {
				end = 1;
				break;
			}
		}

		if (end) {
			break;
		}
		else {
			subnet |= bit;
		}
	}

	int sh = 24;
	int tmp = ip[0] & subnet;
	for (int i = 0; i < 4; i++, sh -= 8) {
		cout << ((tmp >> sh) & (1 << 8) - 1);
		if (i != 3) {
			cout << '.';
		}
	}
	cout << '\n';

	sh = 24;
	for (int i = 0; i < 4; i++, sh -= 8) {
		cout << ((subnet >> sh) & (1 << 8) - 1);
		if (i != 3) {
			cout << '.';
		}
	}
	cout << '\n';
}
