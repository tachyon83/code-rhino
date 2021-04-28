#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<int>v;
vector<int>tree[10];
int a,k,kv;

int value(int a){
    int ret=1;
    for(int i=0;i<a;++i)ret*=2;
    return ret-1;
}

void solve(int s,int e,int d){
    if(s==e){
        tree[d].push_back(v[s]);
        return;
    }
    int mid=(s+e)/2;
    tree[d].push_back(v[mid]);
    solve(s,mid-1,d+1);
    solve(mid+1,e,d+1);
}
void printer(){
    for(int i=0;i<k;++i){
        for(int&e:tree[i])cout<<e<<' ';
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>k;
    kv=value(k);
    for(int i=0;i<kv;++i){
        cin>>a;
        v.push_back(a);
    }
    solve(0,kv-1,0);
    printer();
    return 0;
}
