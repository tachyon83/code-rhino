#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, bomb;
	cin >> str >> bomb;

	vector<char> vc;
	for (char ch : str) {
		vc.push_back(ch);
		if (ch == bomb[bomb.size() - 1]) {
			if (vc.size() - bomb.size() < 0) {
				continue;
			}

			bool flag = true;
			int endIdx = vc.size() - 1;
			for (int i = 0; i < bomb.size(); i++) {
				if (vc[endIdx - i] != bomb[bomb.size() - 1 - i]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				vc.erase(vc.begin() + endIdx +1 - bomb.size(), vc.end());
			}
		}
	}

	if (vc.size() > 0) {
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i];
		}
		cout << '\n';
	}
	else {
		cout << "FRULA\n";
	}

	return 0;
}
