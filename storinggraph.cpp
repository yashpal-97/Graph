------------------TC==O(M)------------------SC==O(N*N)------------------------------------------
#include<bits/stdc++.h>
//yashpal
#define ll long long
#define input for(ll i=0;i<n;i++){ll x;cin>>x;v.push_back(x);}
using namespace std;
signed main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1]={0};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    return 0;
}

----------------------------------------------TC==O(M)-----------------------SC==O(2M)----------------------
//

#include<bits/stdc++.h>
//yashpal
#define ll long long
#define input for(ll i=0;i<n;i++){ll x;cin>>x;v.push_back(x);}
using namespace std;
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);  //will not be used in case of directed graph and space complexity becomes O(M)
    }
    
    return 0;
}








