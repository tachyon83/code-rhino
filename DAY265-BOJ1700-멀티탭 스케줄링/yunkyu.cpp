#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool check[101];
vector<int> v;
vector<int> tap;


int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (check[v[i]]) { // 이미 꼽혀있다면
			continue;
		}

		if (tap.size() < N) { // 멀티탭에 자리가 있다면
			check[v[i]] = true; // 남는자리에 꽂음
			tap.push_back(v[i]); 
		}
		else {
			ans++;
			int ind = 0;
			int maxInd = i;
			for (int j = 0; j < tap.size(); j++) { // 멀티탭에 꽂혀있는 용품중
				bool find = false;
				for (int k = i + 1; k < K; k++) { // 가장 나중에 사용되어질 용품을 찾는다
					if (v[k] == tap[j]) {
						find = true;
						if (maxInd < k) {
							maxInd = k;
							ind = j;
						}
						break;
					}
				}

				if (!find) { // 더 이상 사용하지 않을 용품은 뺀다
					ind = j;
					break;
				}
			}

			// 플러그를 빼고 새 용품을 꼽는다
			check[tap[ind]] = false; 
			tap[ind] = v[i];
			check[tap[ind]] = true;
		}
	}

	printf("%d", ans);
	return 0;
}
