class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        vector<pair<int,int>> info;
        int h=0;
        priority_queue<int>pq;
        pq.push(0);
        
        for(auto building:buildings){
            info.push_back(make_pair(building[0],-1*building[2]));
            info.push_back(make_pair(building[1],building[2]));
        }
        sort(info.begin(),info.end());
        
        for(auto e:info){
            if(e.second<0)pq.push(-1*e.second);
            else{
                vector<int>temp;
                while(pq.top()!=e.second){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                pq.pop();
                for(int p:temp)pq.push(p);
            }
            
            if(h!=pq.top()){
                vector<int>temp2;
                temp2.push_back(e.first);
                temp2.push_back(pq.top());
                skyline.push_back(temp2);
                h=pq.top();
            }
        }
        return skyline;
    }
};
