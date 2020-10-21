#include <iostream>
#include <vector>
#include <set>
//첨에 어떻게 풀지잘몰라서 분리집합 joint해서 푼 블로그를 참고하고품.
//dfs나 bfs로 풀어도 됨.
using namespace std;
struct rec {
	int x1, y1, x2, y2;
};
vector<rec> v;
vector<int>parent;
void join(int i, int j);

int main() {
	rec tmp;
	int num;
	cin >> num;
	tmp.x1 = tmp.y1 = tmp.x2 = tmp.y2 = 0;
	v.push_back(tmp);
	parent.push_back(0);
	for (int i = 0; i < num; i++) {
		cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
		v.push_back(tmp);
		parent.push_back(i+1);
	}
	for (int i = 0; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			join(i, j);
		}
	}
	//set을 이용하여 중복을 베재하며 parent들을 모은다.
	set<int> real;
	for (int i = 0; i <= num; i++) {
		real.insert(parent[i]);
	}
	//갯수-1해야됨
	cout << real.size() - 1;
}

void join(int i,int j) {
	bool join;
	if (parent[i] == parent[j]) {
		return;
	}
	if (v[i].x1>v[j].x2 || v[i].y1>v[j].y2 || v[i].x2<v[j].x1 || v[i].y2<v[j].y1) {
		join = false;
	}
	else if (v[i].x1 < v[j].x1&&v[i].x2>v[j].x2&&v[i].y1<v[j].y1&&v[i].y2 > v[j].y2) {
		join = false;
	}
	else if(v[j].x1 < v[i].x1&&v[j].x2>v[i].x2&&v[j].y1<v[i].y1&&v[j].y2 > v[i].y2){
		join = false;
	}
	else {
		join = true;
	}
	if (join == true) {
		//parent가 같으면 조인이 필요없다.
		if (parent[i] < parent[j]) {
			parent[j] = parent[i];
		}
		else if (parent[i] > parent[j]) {
			parent[i] = parent[j];
		}
	}

}
