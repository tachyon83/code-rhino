#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int start, int target);

typedef struct pos{
	int dif;
	int time;
	int index;
}pos;

struct cmp {
	bool operator()(pos p1, pos p2) {
		if (p2.dif > p1.dif) {
			return true;
		}
		else {
			if (p2.time >= p1.time) return true;
			return false;
		}
	}
};
int main() {
	int N, K;
	cin >> N >> K;
	DFS(5, 17);
}

void DFS(int start,int target) {
	
	priority_queue <pos,vector<pos>,cmp> pq;
	pos tmp = { -abs(target - start) ,0,start };
	pq.push(tmp);
	while (!pq.empty()) {
		pos tmp = pq.top();
		if (tmp.index == target) {
			break;
		}
		pq.pop();
		pq.push({-abs(tmp.index*2-target),tmp.time-1,tmp.index*2});
		pq.push({ -abs(tmp.index + 1 - target),tmp.time - 1,tmp.index +1 });
		pq.push({ -abs(tmp.index - 1 - target),tmp.time - 1,tmp.index -1 });
	}

	cout << -(pq.top().time);
}

//고쳐야됨!!
