#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<pair<int, pair<int, int>>> coords;
vector<pair<int,int>>coordMap;

struct Tree{
    int n,root,previous;
    vector<int>parent;
    vector<int>lc,rc;
    vector<vector<int>>ret;
    vector<int>pre;
    vector<int>post;

    Tree():n(0){}
    Tree(int num):n(num){
        root=0;
        parent.resize(n);
        lc.resize(n,0);
        rc.resize(n,0);
    }
    void preOrder(int root){
        pre.push_back(root);
        if(lc[root]) preOrder(lc[root]);
        if(rc[root]) preOrder(rc[root]);
    }
    void postOrder(int root){
        if(lc[root]) postOrder(lc[root]);
        if(rc[root]) postOrder(rc[root]);
        post.push_back(root);
    }
    void addOrders(){
        ret.push_back(pre);
        ret.push_back(post);
    }
    void makeTree(vector<pair<int, pair<int, int>>> coords){
        int i=0;
        if(!root)root=coords[i].first;

        while(i<(int)coords.size()){
            i++;
            if(i==(int)coords.size())break;
            auto currNum=coords[i].first;
            auto currCoord=coords[i].second;
            auto p=root;

            while(1){
                if(currCoord.first<coordMap[p].first){
                    if(!lc[p]){
                        lc[p]=currNum;
                        parent[currNum]=p;
                        break;
                    }else p=lc[p];
                }else{
                    if(!rc[p]){
                        rc[p]=currNum;
                        parent[currNum]=p;
                        break;
                    }else p=rc[p];
                }
            }
        }
    }
};

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    if (a.second.second < b.second.second)
        return 0;
    if (a.second.second > b.second.second)
        return 1;
    if (a.second.first > b.second.first)
        return 0;
    return 1;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    Tree T((int)nodeinfo.size()+1);
    coordMap.resize((int)nodeinfo.size()+1);
    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        coords.push_back({i + 1, {nodeinfo[i][0], nodeinfo[i][1]}});
        coordMap[i+1]={nodeinfo[i][0], nodeinfo[i][1]};
    }
    sort(coords.begin(), coords.end(), cmp);
    T.makeTree(coords);
    T.preOrder(T.root);
    T.postOrder(T.root);
    T.addOrders();
    return T.ret;
}
