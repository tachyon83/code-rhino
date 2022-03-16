#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
const int sz=5e2+1+1;
int reached[sz],failed[sz];
pair<double,int> failrates[sz];
bool cmp(const pair<double,int>a,const pair<double,int>b){
    if(a.first>b.first)return 1;
    if(a.first<b.first)return 0;
    return a.second<b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(auto e:stages){
        for(int i=1;i<=e;++i)reached[i]++;
        failed[e]++;
    }
    for(int i=0;i<N;++i){
        if(reached[i+1])failrates[i]={failed[i+1]/(double)reached[i+1],i+1};
        else failrates[i]={0,i+1};
    }
    sort(failrates,failrates+N,cmp);
    for(int i=0;i<N;++i)answer.push_back(failrates[i].second);
    return answer;
}
