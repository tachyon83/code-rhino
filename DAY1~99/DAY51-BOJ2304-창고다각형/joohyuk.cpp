#include <iostream>
#include <algorithm>
#include <stack>
#define endl '\n'
#define mp make_pair
using namespace std;
const int sz=1e3+1;
stack<pair<int,int> >st;
int n,l,h,s,holdx,holdy;
pair<int,int>arr[sz];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    for(int i=0;i<n;++i){
        l=arr[i].first;
        h=arr[i].second;
        if(st.empty()){
            // holdx=l;
            holdy=h;
            st.push(mp(l,h));
        }else if(h<holdy)st.push(mp(l,h));
        else{
            while((int)st.size()>1)st.pop();
            s+=(l-st.top().first)*holdy;st.pop();
            holdy=h;st.push(mp(l,h));
        }
    }
    holdx=st.top().first;
    holdy=st.top().second;
    while((int)st.size()>1){
        if(st.top().second>holdy){
            s+=(holdx-st.top().first)*holdy;
            holdx=st.top().first;
            holdy=st.top().second;
        }
        st.pop();
    }
    if(holdx!=st.top().first)s+=(holdx-st.top().first)*holdy;
    s+=st.top().second;
    cout<<s;
    return 0;
}
