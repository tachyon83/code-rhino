#include <iostream>
#define endl '\n'
using namespace std;
const int sz=1<<21;
int s,n,tree1[sz],tree2[sz];
void travel(int i,int d){
    if(i==1){
        travel(i<<1,0);
        travel(i<<1|1,0);
        return;
    }
    if(d+tree2[i]<tree2[1])tree1[i]+=tree2[1]-(d+tree2[i]);
    s+=tree1[i];
    if(i<(1<<n)){
        travel(i<<1,tree1[i]+d);
        travel(i<<1|1,tree1[i]+d);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=2;i<(1<<(n+1));++i)cin>>tree1[i];
    for(int i=(1<<n);i<(1<<(n+1));++i)tree2[i]=tree1[i];
    for(int i=(1<<n)-1;i>0;--i)tree2[i]=max(tree2[i<<1],tree2[i<<1|1])+tree1[i];
    travel(1,0);
    cout<<s;
    return 0;
}
