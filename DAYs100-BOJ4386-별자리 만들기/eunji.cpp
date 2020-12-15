#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
typedef struct {
	double row;
	double col;
}starPos;
typedef struct {
	int from;
	int to;
	double val;
}starRoad;
int par[101];
int comp(const starRoad a, const starRoad b);
bool isCycle(int a, int b);
int find(int a);
int main() {
	int n;
	cin >> n;
	vector<starPos> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i].row >> pos[i].col;
		par[i] = i;
	}
	vector<starRoad> Road;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double val = sqrt(pow(pos[i].row - pos[j].row, 2) + pow(pos[i].col - pos[j].col, 2));
			Road.push_back({ i,j,val });
		}
	}
	sort(Road.begin(), Road.end(), comp);
	double sum = 0.0;
	for (int i = 0; i < Road.size(); i++) {
		if (!isCycle(Road[i].from, Road[i].to)) sum += Road[i].val;
	}
	printf("%.2lf", sum);

}
int comp(const starRoad a, const starRoad b) {
	return a.val < b.val;
}
bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return true;
	par[b] = a;
	return false;
}
int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}
