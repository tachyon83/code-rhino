#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;
const int abc=26;

struct Trie{
    Trie* next[abc];
    bool finished;
    int words;

    Trie(): words(0),finished(0){fill(next,next+26,nullptr);}
    ~Trie(){
        for(int i=0;i<abc;++i){
            if(next[i])delete next[i];
        }
    }
    void insert(const char* word){
        if(*word=='\0'){
            finished=1;
            // branch++;
        }else{
            words++;
            int wordnum=*word-'a';
            if(!next[wordnum]){
                next[wordnum]=new Trie;
            }
            next[wordnum]->insert(word+1);
        }
    }
    int autocomplete(const char* word,int k,int strsz){
        int cnt=0;
        int wordnum=*word-'a';
        if(finished){
            if(k==strsz)return cnt;
            return 1+next[wordnum]->autocomplete(word+1,k+1,strsz);
        }
        if(words>1) return cnt=1+next[wordnum]->autocomplete(word+1,k+1,strsz);
        return 0;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root=new Trie;
    for(auto e:words)root->insert(e.c_str());
    for(auto e:words)answer+=root->autocomplete(e.c_str(),0,(int)e.size());
    return answer;
}
