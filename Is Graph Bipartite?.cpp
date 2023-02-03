
class Solution {
public:
bool check(int node,int V,vector<vector<int>>& graph,vector<int>color){
    queue<int>q;
    q.push(node);
    color[node]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i:graph[x]){
            if(color[i]==-1){
                color[i]= !color[x];
                q.push(i);
            }
            else if(color[i]==color[x]){
                return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int V=graph.size();
      
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(check(i,V,graph,color)==false){
                return false;
            }
        }
        return true;
    }
};


