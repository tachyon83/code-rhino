#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> know;
int used[7];
int cnt = 0;

bool check(int n) {
	int i, j;
	for (i = 0; i < know.size(); i++) {
		bool flag = false;
		for (j = 0; j < n; j++) {
			if (used[j] == know[i]) { 
				flag = true;
				break;
			}
		}
		if (!flag) // 수가 비밀번호에 포함돼있지 않다면 실패
			return false;
	}

	return true;
}

void DFS(int length, int n) {
	if (length == n) { // 조합이 완성 됐다면
		if (check(n)) // 선견지명으로 알게 된 수가 포함 돼있는지 확인
			cnt++;
		return;
	}
	int i;

	for (i = 0; i <= 9; i++) {
		used[length] = i; // 비밀번호의 length번째를 i 숫자로 
		DFS(length + 1, n);
		used[length] = -1;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		know.push_back(num); // 알고 있는 수
	}
	memset(used, -1, sizeof(used));
	DFS(0, n);
	printf("%d", cnt);
	return 0;
}
