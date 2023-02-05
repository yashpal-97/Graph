 bool  dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                if(dfs(it,adj,vis,pathvis)){
                    return true;
                }
            }
            
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,-1);
        vector<int>pathvis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(i,adj,vis,pathvis)){
                    return true;
                }
            }
        }
        return false;
    }
