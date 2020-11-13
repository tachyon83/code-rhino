
//최단거리로 가는 경우의 수는 가로N 세로M개를 정렬하는 방법과 같다
//(M+N)! / (M! * N!)
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (n-- > m--) {
			int tmp = m;
			m = n;
			n = tmp;
		}
		if (n == 0) return 1;
		return (int)(dofac(m + n, m) / dofac(n, 0));
	}
	long long dofac(int end, int start) {
		long long total = end;
		for (int i = end - 1; i > start; i--) {
			total *= i;
		}
		return total;
	}
};
