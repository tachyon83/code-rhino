#include <string>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int p[10];
queue<pii>q;

int solution(vector<int> priorities, int location) {
    int i=0;
    for(int e:priorities){
        p[e]++;
        q.push(mp(e,i++));
    }
    int pos=0;
    for(int i=0;i<10;++i){
        if(p[i])pos=i;
    }
    int answer = 0;
    while(!q.empty()){
        while(q.front().first<pos){
            q.push(q.front());
            q.pop();
        }
        answer++;
        p[pos]--;
        if(q.front().second==location)break;
        q.pop();
        while(!p[pos])pos--;
    }
    return answer;
}
