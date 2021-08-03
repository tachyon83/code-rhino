#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define endl '\n'
using namespace std;

struct Ant{
    unordered_map<string,Ant*> um;
    vector<string> keys;
    ~Ant(){
        for(auto itr=um.begin();itr!=um.end();itr++){
            delete um[itr->first];
        }
    }
    Ant* insert(const string w){
        if(um.find(w)==um.end()){
            um[w]=new Ant;
            keys.push_back(w);
        }
        return um[w];
    }
};
Ant* root;

void explore(Ant* curr,int d){
    sort(curr->keys.begin(),curr->keys.end());
    for(auto key:curr->keys){
        for(int i=0;i<d*2;++i)cout<<'-';
        cout<<key<<endl;
        explore(curr->um[key],d+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    root=new Ant;
    Ant* curr=root;
    int n,k;
    string str;
    cin>>n;
    while(n--){
        cin>>k;
        while(k--){
            cin>>str;
            curr=curr->insert(str);
        }
        curr=root;
    }
    explore(root,0);
    return 0;
}
