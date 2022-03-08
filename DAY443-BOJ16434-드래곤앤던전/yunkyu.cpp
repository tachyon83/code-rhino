#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll, pair<ll, ll>>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll initAttack;
	cin >> n >> initAttack;

	ll t, a, h;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		v.push_back({ t,{a,h} });
	}

	ll low = 0, high = 1e18;
	while (low <= high) { // 이분 탐색 시작
		ll mid = (low + high) / 2; // 중간값
		ll attack = initAttack; // 용사의 초기 공격력
		ll hp = mid; // 용사의 초기 생명력
		for (int i = 0; i < n; i++) {
			t = v[i].first;
			a = v[i].second.first;
			h = v[i].second.second;
			if (t == 1) { // 방에 몬스터가 있을때
				if (h % attack == 0) hp -= (h / attack - 1) * a; // 용사가 먼저 죽이면 몬스터는 공격할수 없기때문에 1을 뺀다
				else hp -= (h / attack) * a;

				if (hp <= 0) { // 용사가 죽으면
					break;
				}
			}
			else { // 방에 포션이 있을때
				attack += a;
				hp = min(hp + h, mid); // 포션으로 최대 hp를 넘어설수 없다.
			}
		}

		if (hp <= 0) { // 용사가 죽었다면 체력을 mid보다 높여본다.
			low = mid + 1;
		}
		else { // 용사가 살았다면 체력을 mid보다 낮춰본다.
			high = mid - 1;
		}
	}

	cout << low << '\n';
	return 0;
}
