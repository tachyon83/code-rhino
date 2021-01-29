#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vc(55, 0);

int getParent(int n) {
	if (vc[n] == n) {
		return n;
	}
	return vc[n] = getParent(vc[n]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		vc[b] = a;
	}
	else {
		vc[a] = b;
	}
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		vc[i] = i;
	}

	vector<int> vcChk;

	int num;
	cin >> num;

	/*if (num == 0) {
		cout << M << '\n';
		return 0;
	}*/

	while (num--) {
		int tmp;
		cin >> tmp;
		vcChk.push_back(tmp);	//진실을 아는사람 체크
	}

	vector<int> party[55];
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;

		for (int j = 0; j < tmp; j++) {
			int p;
			cin >> p;
			party[i].push_back(p);
		}
	}

	for (int i = 0; i < M; i++) {
		int a = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int b = party[i][j];
			unionParent(a, b);
		}
	}

	int chk = 0;
	for (int i = 0; i < M; i++) {
		bool trueChk = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (trueChk == false) {
				break;
			}

			int tmp = party[i][j];
			for (int k = 0; k < vcChk.size(); k++) {
				int n = vcChk[k];
				if (findParent(tmp, n) == true) {
					trueChk = false;
					break;
				}
			}
		}

		if (trueChk) {
			chk++;
		}
	}

	cout << chk << '\n';

}
