class Solution {
    bool visited[21];
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(2 * n - 1,0); 
        memset(visited,false,sizeof(visited));
        dfs(v,0,n);
        return v;
    }
    
    bool dfs(vector<int> &v, int ind, int n){
        if(ind == v.size()){ 
            return true;
        }
        
        if(v[ind]){
            return dfs(v,ind + 1,n);
        }
        
        for(int i=n; i>=1; i--){
            if(!visited[i]){
                visited[i] = true;
                if(i == 1){
                    v[ind] = i;
                    if(dfs(v,ind + 1, n)) return true;
                    v[ind] = 0;
                }
                else {
                    if(ind + i >= v.size() || v[ind + i]) {
                        visited[i] = false;
                        continue;
                    }
                    v[ind] = v[ind + i] = i;
                    if(dfs(v,ind + 1 ,n)) return true;
                    v[ind] = v[ind + i] = 0;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
};
