/*   Number of Good Components    [ MEDIUM ] */

class Solution {
  public:
      void dfs(int i,int s,vector<vector<int>> &adj,vector<int> &vis,bool &a,int &node){
        vis[i]=1;
        node++;
        if(s!=adj[i].size()){
            a=false;
        }
        for(auto x:adj[i]){
            if(!vis[x])dfs(x,s,adj,vis,a,node);
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(v+1);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=0;
        vector<int> vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                int node=0;
                bool a=true;
                dfs(i,adj[i].size(),adj,vis,a,node);
                if(a and node-1==adj[i].size())ans++;
            }
        }
        return ans;
    }
};
