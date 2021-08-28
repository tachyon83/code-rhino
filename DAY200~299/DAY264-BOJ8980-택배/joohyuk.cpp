#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=2e3+1;
vector<pii> pickup[sz];
int drop[sz],n,c,m,u,v,x,t,hold;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

	cin>>n>>c>>m;
	while(m--){
		cin>>u>>v>>x;
		pickup[u].push_back(mp(v,x));
	}
	for(int i=1;i<=n;++i)sort(pickup[i].begin(),pickup[i].end());
	for(int i=1;i<=n;++i){
		t+=drop[i];
		hold-=drop[i];
		for(int j=0;j<pickup[i].size();++j){
			auto& cp=pickup[i][j];
			if(hold+cp.second>c){
				drop[cp.first]+=c-hold;
				cp.second-=c-hold;
				hold=c;

				int k=n;
				while(cp.second&&k>cp.first){
					if(cp.second>=drop[k]){
						cp.second-=drop[k];
						drop[cp.first]+=drop[k];
						drop[k]=0;
						k--;
					}else{
						drop[cp.first]+=cp.second;
						drop[k]-=cp.second;
						cp.second=0;
					}
				}
			}else{
				hold+=pickup[i][j].second;
				drop[pickup[i][j].first]+=pickup[i][j].second;
			}
		}
	}
	cout<<t;
	return 0;
}
