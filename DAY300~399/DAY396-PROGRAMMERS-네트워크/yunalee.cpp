#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> parent;

struct edge{
    int x;
    int y;
};

int getParent(int x){
    if(parent[x] == x){
        return parent[x];
    }
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

bool findParent(int a, int b){
    a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	return false;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<edge> vc;
    edge eg;
    
    parent.resize(n, 0);
    
    set<int> s;
    for(int i = 0; i < n; i++){
        parent[i] = i;
        for(int j = 0; j < n; j++){
            if(i != j && computers[i][j] == 1){
                eg.x = i;
                eg.y = j;
                vc.push_back(eg);
                eg.x = j;
                eg.y = i;
                vc.push_back(eg);
            }
        }
    }
    
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < vc.size(); i++){
            if(!findParent(vc[i].x, vc[i].y)){
                flag = true;
                unionParent(vc[i].x, vc[i].y);
            }
        }
    }
    
    
    
    for(int i = 0; i < n; i++){
        s.insert(parent[i]);
    }
    
    return s.size();
}
