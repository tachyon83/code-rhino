#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	int t, a, h;
};
int n, attack;
info map[123456];

bool canRescue(long long int maxHp){
	long long int curHp = maxHp, curAttack = attack;

	for(int i = 0; i < n; ++i) {
		if (map[i].t == 1) {
			if ((map[i].h - 1) / curAttack > (curHp - 1) / map[i].a)
				return false;
			curHp -= (map[i].h - 1) / curAttack * map[i].a;
		}
		else {
	
			curAttack += map[i].a;
			curHp = min(maxHp, curHp + map[i].h);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> attack;
	for (int i = 0; i < n; ++i) {
		cin >> map[i].t >> map[i].a >> map[i].h;
	}
	long long int l = 1, r = 1e18;

	while (l <= r) {
		long long int mid = (l + r) / 2;
		if (canRescue(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}
