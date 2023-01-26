//-------------------TC==O(N)+o(E*2)----------------SC==O(N)------------------//

int dfs(int node,vector<int>adj[],int vis[],vector<int>&v){
       vis[node]=1;
       v.push_back(node);
       for(auto i:adj[node]){
           if(!vis[i]){
               dfs(i,adj,vis,v);
           }
       }
   }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
    
        vector<int>v;
        dfs(0,adj,vis,v);
        return v;
         }
