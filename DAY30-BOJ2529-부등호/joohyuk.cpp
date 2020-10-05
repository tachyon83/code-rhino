#include <iostream>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;
int c,k,ans[10];
char tmp,ops[10];
bool visited[10];

bool mxSolve(int cnt){
    if(cnt==k+1)return 1;
    if(!cnt){
        for(int i=9;i>=0;--i){
            if(visited[i])continue;
            ans[cnt]=i;
            visited[i]=1;
            if(mxSolve(cnt+1))return 1;
            visited[i]=0;
        }
    }else{
        for(int i=9;i>=0;--i){
            if(visited[i])continue;
            ans[cnt]=i;
            visited[i]=1;
            if(ops[cnt-1]=='<' && ans[cnt-1]<ans[cnt]){
                if(mxSolve(cnt+1))return 1;
            }else if(ops[cnt-1]=='>' && ans[cnt-1]>ans[cnt]){
                if(mxSolve(cnt+1))return 1;
            }
            visited[i]=0;
        }
    }
    return 0;
}
void printer(){
    string ret="";
    for(int i=0;i<=k;++i){
        ret+=(char)(ans[i]+'0');
    }
    cout<<ret<<endl;
}

bool mnSolve(int cnt){
    if(cnt==k+1)return 1;
    if(!cnt){
        for(int i=0;i<=9;++i){
            if(visited[i])continue;
            ans[cnt]=i;
            visited[i]=1;
            if(mnSolve(cnt+1))return 1;
            visited[i]=0;
        }
    }else{
        for(int i=0;i<10;++i){
            if(visited[i])continue;
            ans[cnt]=i;
            visited[i]=1;
            if(ops[cnt-1]=='<' && ans[cnt-1]<ans[cnt]){
                if(mnSolve(cnt+1))return 1;
            }else if(ops[cnt-1]=='>' && ans[cnt-1]>ans[cnt]){
                if(mnSolve(cnt+1))return 1;
            }
            visited[i]=0;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>k;
    while(c<k){
        cin>>tmp;
        if(tmp==' ')continue;
        ops[c++]=tmp;
    }
    mxSolve(0);
    printer();
    memset(visited,0,sizeof(visited));
    mnSolve(0);
    printer();
    return 0;
}
