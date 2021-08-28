#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arc;
vector<int> mTap;
int answer = 0;

int main() {
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		arc.push_back(tmp);
	}

	vector<int>::iterator iter;
	for (int i = 0; i < M; i++) {
		iter = find(mTap.begin(), mTap.end(), arc[i]);

		//멀티탭에 남는 구멍이 있는 경우
		if (mTap.size() < N) {
			// 현재 멀티탭에 꽂혀있지 않는 경우
			if (iter == mTap.end()) {
				mTap.push_back(arc[i]);
			}
			continue;
		}
		
		//멀티탭에 남는 구멍이 없는 경우
		if (mTap.size() >= N) {
			// 현재 멀티탭에 꽂혀있지 않는 경우
			if (iter == mTap.end()) {
				int idx = 0, num = 0;
				// 뒤에 사용되지 않을 전자기기이거나 가장 나중에 쓰이는 전자기기를 뽑는다
				for (int j = 0; j < N; j++) {
					int cnt = 0;
					for (int k = i + 1; k < M; k++) {
						if (arc[k] == mTap[j]) {
							break;
						}
						cnt++;
					}
					if (cnt > idx) {
						num = j;
						idx = cnt;
					}
				}
				answer++;
				mTap[num] = arc[i];
			}
		}
	}
	cout << answer << '\n';
}
