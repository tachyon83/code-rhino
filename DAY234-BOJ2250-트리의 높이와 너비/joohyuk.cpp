#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int d=1e4+5,sz=1e4+5;
int n,a,b,c,p[sz],children[sz][2],root,cnt[sz][2],mx,mxd,dmx;
vector<int>lv[d];

int process(int curr){
    for(int i=0;i<2;++i){
        if(children[curr][i]!=-1)cnt[curr][i]=process(children[curr][i]);
    }
    return cnt[curr][0]+cnt[curr][1]+1;
}

void measure(int curr,int mode,int value,int depth){
    dmx=max(dmx,depth);
    if(mode)lv[depth].push_back(value-cnt[curr][1]);
    else lv[depth].push_back(value+cnt[curr][0]);
    if(children[curr][0]!=-1)measure(children[curr][0],0,lv[depth][(int)lv[depth].size()-1]-cnt[curr][0],depth+1);
    if(children[curr][1]!=-1)measure(children[curr][1],1,lv[depth][(int)lv[depth].size()-1]+cnt[curr][1],depth+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        children[a][0]=b;
        children[a][1]=c;
        p[b]=a;p[c]=a;
    }
    for(int i=1;i<n+1;++i){
        if(!p[i]){
            root=i;
            break;
        }
    }
    process(root);
    measure(root,1,n,1);
    for(int i=1;i<=dmx;++i){
        int lvsz=(int)lv[i].size();
        if(!lvsz)continue;
        int width=lv[i][(int)lv[i].size()-1]-lv[i][0]+1;
        if(mx<width){
            mx=width;
            mxd=i;
        }
    }
    cout<<mxd<<' '<<mx;
    return 0;
}
