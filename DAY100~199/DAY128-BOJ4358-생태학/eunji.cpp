//주의점! 반드시 네자리까지 출력 (4.3-> 4.3000)
#include<iostream>
#include<cmath>
#include<string>
#include<map>
using namespace std;
int main() {
	int num = 0;
	map<string, int> m;
	string s;

	//입력
	while (getline(cin, s)) {
		if (m.end() == m.find(s)) m.insert(make_pair(s, 1));
		else m[s]++;
		num++;
	}
	//출력
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << itr->first;
		printf(" %.4f\n",(itr->second) * 100.0 / num);
	}
}
