#include <cstdio>
#include <vector>
using namespace std;

vector<int> sequence; 
int cnt = 0;

void DFS(int sum ,int index, int s) {
	if (index == sequence.size()) { // 배열 끝까지 조사했을 경우 종료
		return;
	}

	//각 배열의 값을 더한것과 더하지 않았을 때로 분리
	for (int i = index; i < sequence.size(); i++) {
		sum += sequence[i];
		if (sum == s) cnt++; //부분수열이 s일 경우 count +
		DFS(sum, i + 1, s);
		sum -= sequence[i];
	}
}

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		int a; 
		scanf("%d", &a);
		sequence.push_back(a);
	}

	DFS(0, 0, s);
	printf("%d", cnt);
	return 0;
}
