#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int sz=1e4;
string temp;
char x;
int o,n,m,w[sz],cnt,miss;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>temp;
		for(int j=0;j<(int)temp.size();++j)w[i]|=1<<(temp[j]-'a');
	}
	for(int i=0;i<m;++i){
		cin>>o>>x;
		if(o-1)miss^=1<<(x-'a');
		else miss|=1<<(x-'a');
		cnt=n;
		for(int j=0;j<n;++j)if(w[j]&miss)cnt--;
		cout<<cnt<<endl;
	}
	return 0;
}
