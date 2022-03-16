#include <iostream>
#include <cstring>

using namespace std;

string key;

struct Trie{
    bool finish;
    Trie* next[26];

    Trie() : finish(false){
        memset(next, 0, sizeof(next));
    }

    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(next[i]){
                delete next[i];
            }
        }
    }

    void insert(int idx){
        if(idx >= key.size()){
            finish = true;
        }else{
            int curr = key[idx] - 'a';
            if(next[curr] == NULL){
                next[curr] = new Trie();
            }
            next[curr]->insert(idx + 1);
        }
    }

    bool find(int idx){
        if(idx >= key.size()){
            if(finish){
                return true;
            }
            return false;
        }

        int curr = key[idx] - 'a';
        if(next[curr] == NULL){
            return false;
        }

        return next[curr]->find(idx + 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> key;
        trie.insert(0);
    }

    int result = 0;
    for(int i = 0; i < M; i++){
        cin >> key;

        if(trie.find(0)){
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}
