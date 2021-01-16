#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	double cnt = 0;
	map<string, int> tree;
	string str;
	while (getline(cin, str)) {
		tree[str] = tree[str] == 0 ? 1 : tree[str] + 1;
		cnt += 1;
	}
	cout.precision(4);
	for (auto it = tree.begin(); it != tree.end(); it++) {
		cout << fixed << it->first << ' ' << (double)it->second / cnt * 100 << '\n';
	}
}