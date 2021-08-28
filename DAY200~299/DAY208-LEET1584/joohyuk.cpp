#include<cstdlib>
#include<algorithm>
#define mp make_pair
class Solution {
private:
    int dist(vector<int>a,vector<int>b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int find(int a){
        if(root[a]==a)return a;
        return root[a]=find(root[a]);
    }
    
public:
    int root[1001];
    vector<pair<int,pair<int,int> > >d;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int k=0,t=0;
        for(auto&p:points){
            root[k]=k;
            k+=1;
        }
        for(int i=0;i<k;++i){
            for(int j=i+1;j<k;++j){
                if(i==j)continue;
                d.push_back(mp(dist(points[i],points[v]),mp(i,j)));
            }
        }
        sort(d.begin(),d.end());
        for(auto&e:d){
            int a=find(e.second.first);
            int b=find(e.second.second);
            if(a!=b){
                t+=e.first;
                root[a]=b;
            }
        }
        return t; 
    }
};
