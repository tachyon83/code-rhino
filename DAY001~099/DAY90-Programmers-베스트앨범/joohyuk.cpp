#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#define endl '\n'
using namespace std;

struct Node {
    int a, b;
    bool operator<(const Node &n) const {
        if(a!=n.a)return a < n.a;
        return b > n.b;
    }
};

unordered_map<string,int>um1;
unordered_map<string,int>um2;
unordered_map<string,priority_queue<Node> >um3;
priority_queue<pair<int,string> >pq1;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int sz=(int)plays.size();
    for(int i=0;i<sz;++i){
        Node nd;
        nd.a=plays[i];nd.b=i;
        if(um1.find(genres[i])==um1.end()){
            um1[genres[i]]=plays[i];
            um2[genres[i]]=2;
            priority_queue<Node>tempPq;
            um3[genres[i]]=tempPq;
        }else um1[genres[i]]+=plays[i];
        um3[genres[i]].push(nd);
    }
    for(auto p:um1)pq1.push(make_pair(p.second,p.first));
    vector<int> answer;
    while(!pq1.empty()){
        string curr=pq1.top().second;pq1.pop();
        while(!um3[curr].empty()&&um2[curr]){
            int id=um3[curr].top().b;
            um3[curr].pop();um2[curr]--;
            answer.push_back(id);
        }
    }
    return answer;
}
