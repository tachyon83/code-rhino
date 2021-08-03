#include <iostream>
#include <string>
#include <unordered_set>
#define endl '\n'
using namespace std;

const int bsz=4,limit=8;
int w,n,num,cnt,score,dr[8]={0,1,0,-1,-1,-1,1,1},dc[8]={1,0,-1,0,-1,1,-1,1};
int st[8+1]={0,0,0,1,1,2,3,5,11};
bool flag;
string word,lw,hold;
char board[4][4];
unordered_set<string>us;

struct Trie{
    bool end;
    Trie* nx[26];
    Trie():end(0){fill(nx,nx+10,nullptr);}
    ~Trie(){for(int i=0;i<10;++i)delete nx[i];}

    void insert(const char* wordptr){
        if(*wordptr=='\0'){
            end=1;
            return;
        }
        int abc=*wordptr-'A';
        if(!nx[abc])nx[abc]=new Trie;
        nx[abc]->insert(wordptr+1);
    }
};
Trie* root;

void solve(Trie* currTrie, int i,int j,string hold){
    if((int)hold.size()>=limit)return;
    int pos=board[i][j]-'A';
    if(!(currTrie->nx[pos]))return;
    hold+=board[i][j];
    if(currTrie->nx[pos]->end){
        if(us.find(hold)==us.end()){
            us.insert(hold);
            cnt++;
            score+=st[(int)hold.size()];
            if((int)hold.size()>(int)lw.size())lw=hold;
            else if((int)hold.size()==(int)lw.size()){
                if(hold<lw)lw=hold;
            }
        }
    }
    for(int idx=0;idx<8;++idx){
        int nr=i+dr[idx];
        int nc=j+dc[idx];
        if(0<=nr&&nr<bsz&&0<=nc&&nc<bsz){
            solve(currTrie->nx[pos],nr,nc,hold);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>w;
    root=new Trie;
    while(w--){
        cin>>word;
        root->insert(word.c_str());
    }
    cin>>w;
    while(w--){
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                cin>>board[i][j];
            }
        }

        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                solve(root,i,j,hold);
            }
        }
        cout<<score<<' '<<lw<<' '<<cnt<<endl;
        score=0,cnt=0,lw="",hold="";
        us.clear();
    }
    return 0;
}
