#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[55][55];
vector<pair<int, int>> vc;
vector<pair<int, int>> vcP;
vector<pair<int, int>> vcCh;
int dirX[4] = { 0, -1, 0 ,1 };
int dirY[4] = { -1, 0, 1, 0 };
int n, m;
int minDir = 987987897;

void solution(int cnt, int k, int start, int m) {
	if (cnt == k) {	// k개 만큼의 치킨집을 선택한 경우
		int sum = 0;
		//각 집마다 치킨거리 구하기
		for (int i = 0; i < vcP.size(); i++) {
			int subMin = 987897987;

			//하나의 집 좌표를 기준으로 선택된 치킨집들 중 치킨거리 구하기
			for (int j = 0; j < vcCh.size(); j++) {
				int dirGap = abs(vcP[i].first - vcCh[j].first) + abs(vcP[i].second - vcCh[j].second);
				if (dirGap < subMin) {
					subMin = dirGap;
				}
			}
			sum += subMin;
		}
		if (minDir > sum) {
			minDir = sum;
		}

		return;
	}

	for (int i = start; i < vc.size(); i++) {
		vcCh.push_back(make_pair(vc[i].first, vc[i].second));	//치킨집 선택
		solution(cnt + 1, k, i + 1, m);
		vcCh.erase(vcCh.begin() + (vcCh.size() - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				vc.push_back(make_pair(i, j));	//치킨집 좌표 저장
			}
			if (arr[i][j] == 1) {
				vcP.push_back(make_pair(i, j));	//집 좌표 저장
			}
		}
	}

	//치킨집을 1개부터 최대 m개 선택
	for (int i = 1; i <= m; i++) {
		solution(0, i, 0, m);
	}

	cout << minDir << '\n';

	return 0;
}
