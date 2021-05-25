#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

const int sz=1<<20;
bool vis[sz],flag;
stack<int>st;
int n,q,a,curr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n>>q;
    while(q--){
    	flag=0;
    	cin>>a;
    	while(a){
    		st.push(a);
    		a>>=1;
    	}
    	while(!st.empty()){
    		curr=st.top();st.pop();
    		if(vis[curr]){
    			cout<<curr<<endl;
    			flag=1;
    			break;
    		}
    	}
    	if(!flag){
    		vis[curr]=1;
    		cout<<0<<endl;
    	}
    	while(!st.empty())st.pop();
    }
    return 0;
}
