//-------------------TC==O(V*V)---------------------SC==O(V)+O(V)------------------------//
class Solution {
public:
void dfs(int node,vector<int>q[],vector<int>&vis){
    vis[node]=1;
    for(auto it:q[node]){
        if(!vis[it]){
            dfs(it,q,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>q[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&i!=j){
                    q[i].push_back(j);
                    q[j].push_back(i);
                }
            }
        }
        vector<int>vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,q,vis);
            }
        }
return cnt;
    }
};


//--------------------------TC==O(V*V)--------------------SC==O(V)+O(V)--------------------------------------//

class Solution {
public:
  void bfs1(int i, vector<int> adj[],vector<int>&vis) {
         vis[i]=1;
        queue<int>q;
        q.push(i);
        vector<int>bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto &i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }  }
  
    int findCircleNum(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>q[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&i!=j){
                    q[i].push_back(j);
                    q[j].push_back(i);
                }
            }
        }
        int cnt=0;
     vector<int>vis(V+1,0);
     for(int i=0;i<V;i++){
         if(!vis[i]){
             cnt++;
             bfs1(i,q,vis);
         }
     }
    
        return cnt;
    }
};



