//Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
//Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

//------------------TC==O(N+2*E)----------SC==O(N)--------------------------------

bool detect(int src,vector<int>adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V+1]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }


//---------------------------------------------------Time Complexity: O(N + 2E) + O(N)--------------------SC==O(N)------------------------


 bool detect(int src,int parent,vector<int>adj[],int vis[]){
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                
                if(detect(it,src,adj,vis)){
                    return true;
                }
            }
                else if(it!=parent){
                    return true;
                }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,adj,vis)){
                return  true;
                }
            }
        }
        return false;
    }


















