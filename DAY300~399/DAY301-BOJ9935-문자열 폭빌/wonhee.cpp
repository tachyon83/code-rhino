#include<iostream>
using namespace std;
char str[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	string bomb; cin >> bomb;
	int pos = 0, size = s.size();

	for (int i = 0; i < size; ++i){
		str[pos++] = s[i];
		if (str[pos - 1] == bomb[bomb.size() - 1]){
			if (pos - bomb.size() < 0) continue;

			bool detected = true;
			for (int j = 0; j < bomb.size(); ++j){
				if (str[pos - j - 1] != bomb[bomb.size() - j - 1]){
					detected = false;
					break;
				}
			}
			if (detected) pos -= bomb.size();
		}
	}

	if (pos == 0) cout << "FRULA\n";
	else{
		for (int i = 0; i < pos; i++)
			cout << str[i];
	}
	return 0;
}