#include <cstdio>
#include <bitset>
using namespace std;

bitset<(1<<25)>bs;
int n;

int main() {
	while(scanf("%d ",&n)!=-1){
		if(!bs[n]){
			bs[n]=1;
			printf("%d ",n);
		}
	}
	return 0;
}
