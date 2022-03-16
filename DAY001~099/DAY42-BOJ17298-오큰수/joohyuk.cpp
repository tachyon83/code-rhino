#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;
const int sz=1e6;
int n,arr[sz],ret[sz];
stack<pair<int,int> >st;
void solve(int idx){
    if(st.empty()){
        st.push(make_pair(arr[idx],idx));
        solve(idx+1);
        return;
    }
    if(idx==n){
        while(!st.empty()){
            ret[st.top().second]=-1;
            st.pop();
        }
        return;
    }
    while(!st.empty() && arr[idx]>st.top().first){
        ret[st.top().second]=arr[idx];
        st.pop();
    }
    if(st.empty())return;
    st.push(make_pair(arr[idx],idx));
    solve(idx+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i];
    for(int i=0;i<n;++i)if(!ret[i])solve(i);
    for(int i=0;i<n;++i)cout<<ret[i]<<' ';
    return 0;
}
