#include <iostream>
using namespace std;

int n,mask,board[20],temp[20],mn=401;
char c[20];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;++i){
    	mask=0;
    	for(int j=0;j<n;++j){
    		cin>>c[j];
    		if(c[j]=='H')mask|=1<<j;
    	}
    	board[i]=mask;
    }
    
    for(int i=0;i<(1<<n);++i){
    	for(int k=0;k<n;++k)temp[k]=board[k];
    	for(int j=0;j<n;++j)if(i&(1<<j))temp[j]=~temp[j];

		int s=0;
    	for(int j=0;j<n;++j){
    		int curr=0;
    		for(int k=0;k<n;++k)if(temp[k]&(1<<j))curr++;
    		curr=min(curr,n-curr);
    		s+=curr;
    	}
    	mn=min(mn,s);
    }
    cout<<mn;
	return 0;
}
