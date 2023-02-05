
class Solution {
public:
 bool  dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                if(dfs(it,adj,vis,pathvis,check)){
                    check[node]=0;
                    return true;
                }
            }
            
            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
         vector<int>vis(V,-1);
        vector<int>pathvis(V,-1);
        vector<int>safe;
        vector<int>check(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                dfs(i,graph,vis,pathvis,check);
                    }
        }
        for(int i=0;i<V;i++){
            if(check[i]){
                safe.push_back(i);
            }
        }
        return safe;
    }
};





