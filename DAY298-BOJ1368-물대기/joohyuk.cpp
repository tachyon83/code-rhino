#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=300+1;
int root[sz],w,n,cost[sz][sz],ans;
vector<pair<int,pii> >cv;

int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    root[a]=b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=0;i<n+1;++i)root[i]=i;
    for(int i=0;i<n;++i){
        cin>>w;
        cv.push_back(mp(w,mp(0,i+1)));
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>cost[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            cv.push_back(mp(cost[i][j],mp(i+1,j+1)));
        }
    }
    sort(cv.begin(),cv.end());
    for(auto epp:cv){
        auto ep=epp.second;
        if(find(ep.first)!=find(ep.second)){
            merge(ep.first,ep.second);
            ans+=epp.first;
        }
    }
    cout<<ans;
    return 0;
}
