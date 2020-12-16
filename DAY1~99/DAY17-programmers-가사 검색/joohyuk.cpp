#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define endl '\n'
using namespace std;
const int abc=26;
unordered_map<string,int>um;

struct RevTrie{
    RevTrie* next[abc];
    bool finished;
    int wordcnt;
    RevTrie():wordcnt(0),finished(0){fill(next,next+abc,nullptr);}
    ~RevTrie(){
        for(int i=0;i<abc;++i){
            if(next[i])delete next[i];
        }
    }
    void insert(string::reverse_iterator word,string::reverse_iterator wordfront){
        if(word==wordfront)finished=1;
        else{
            wordcnt++;
            int wordnum=*word-'a';
            if(!next[wordnum])next[wordnum]=new RevTrie;
            word++;
            next[wordnum]->insert(word,wordfront);
        }
    }
    int cnt(string::reverse_iterator word,string::reverse_iterator wordfront,int k,int sz){
        int ret=0;
        char temp=*word;
        int wordnum=*word-'a';
        if(finished && k==sz)return 1;
        if(*word=='?'){
            for(int i=0;i<abc;++i){
                if(next[i]){
                    ret+=next[i]->cnt(word+1,wordfront,k+1,sz);
                }
            }
            return ret;
        }
        if(word==wordfront)return 0;
        if(next[wordnum]){
            return next[wordnum]->cnt(word+1,wordfront,k+1,sz);
        }
        return 0;
    }
};

struct Trie{
    Trie* next[abc];
    bool finished;
    int wordcnt;
    Trie():wordcnt(0),finished(0){fill(next,next+abc,nullptr);}
    ~Trie(){
        for(int i=0;i<abc;++i){
            if(next[i])delete next[i];
        }
    }
    void insert(const char* word){
        if(*word=='\0')finished=1;
        else{
            wordcnt++;
            int wordnum=*word-'a';
            if(!next[wordnum])next[wordnum]=new Trie;
            next[wordnum]->insert(word+1);
        }
    }
    int cnt(const char* word,int k,int sz){
        int ret=0;
        int wordnum=*word-'a';
        if(finished && k==sz)return 1;
        if(*word=='?'){
            for(int i=0;i<abc;++i){
                if(next[i])ret+=next[i]->cnt(word+1,k+1,sz);
            }
            return ret;
        }
        if(*word=='\0')return 0;
        if(next[wordnum])return next[wordnum]->cnt(word+1,k+1,sz);
        return 0;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie* root=new Trie;
    RevTrie* revroot=new RevTrie;

    for(auto e:words)root->insert(e.c_str());
    for(auto e:words)revroot->insert(e.rbegin(),e.rend());

    for(auto e:queries){
        if(um.find(e)!=um.end()){}
        else if(e[0]=='?'){
            um[e]=revroot->cnt(e.rbegin(),e.rend(),0,(int)e.size());
        }else {
            um[e]=root->cnt(e.c_str(),0,(int)e.size());
        }
        answer.push_back(um[e]);
    }
    return answer;
}
