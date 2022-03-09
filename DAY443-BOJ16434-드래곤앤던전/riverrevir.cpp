#include <bits/stdc++.h>
using namespace std;
long long result = 1, attack;
int num;
struct info {
	int t, a, h;
};
info arr[123457];

bool cal(long long mid) {
	long long tmp = mid;
	long long mtr_atk, mtr_hp, atk = attack;
	for (int i = 0; i < num; i++) {		
		if (arr[i].t == 1) {
			mtr_atk = arr[i].a;
			mtr_hp = arr[i].h;
			long long wlife = tmp / mtr_atk;
			if (tmp % mtr_atk != 0) wlife += 1;
			long long mlife = mtr_hp / atk;
			if (mtr_hp % atk != 0) mlife += 1;
			if (mlife > wlife) return false;
			tmp -= (mtr_atk*(mlife - 1));
		}
		else if (arr[i].t == 2) {
			atk += arr[i].a;
			tmp += arr[i].h;
			if (mid < tmp) tmp = mid;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> attack;
	for (int i = 0; i < num; i++) {
		cin >> arr[i].t >> arr[i].a >> arr[i].h;
	}
	long long l = 1, r = LLONG_MAX, m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (cal(m)) {
			result = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	cout << result;
}
