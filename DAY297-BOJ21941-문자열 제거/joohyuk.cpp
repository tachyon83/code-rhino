#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int sz=1e3+1,msz=1e2+1;
string s,p[msz];
int ssz,m,pts[sz],ff[msz][sz],w[msz],where[msz][sz];

void kmp(int idx){
    string& s=p[idx];
    int psz=s.length();
    
    for(int i=1,j=0;i<psz;++i){
        while(j&&s[i]!=s[j])j=ff[idx][j-1];
        if(s[i]==s[j])ff[idx][i]=++j;
    }
}

void search(int idx){
    int psz=p[idx].length();
    for(int i=0,j=0;i<ssz;++i){
        while(j&&s[i]!=p[idx][j])j=ff[idx][j-1];
        if(s[i]==p[idx][j]){
            if(++j==psz){
                where[idx][i-j+1]=1;
                j=ff[idx][j-1];
            }
        }
    }
}

int solve(int pos){
    if(pos>=ssz)return 0;
    if(pts[pos])return pts[pos];
    pts[pos]=max(pts[pos],1+solve(pos+1));
    for(int i=0;i<m;++i){
        if(where[i][pos])pts[pos]=max(pts[pos],w[i]+solve(pos+p[i].length()));
    }
    return pts[pos];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>s>>m;
    ssz=s.length();
    for(int i=0;i<m;++i){
        cin>>p[i]>>w[i];
        kmp(i);
        search(i);
    }

    cout<<solve(0);
    return 0;
}
