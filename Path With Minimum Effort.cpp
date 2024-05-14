/*   Path With Minimum Effort   [ Medium ]  */

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(rows,vector<int> (columns,INT_MAX));
        q.push({0,{0,0}});
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        while(q.size()){
            auto temp = q.front();
            q.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            int dis=temp.first;
            for(int k=0;k<4;k++){
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0 and newj>=0 and newi<rows and newj<columns){
                    int newd = max(dis,abs(heights[i][j]-heights[newi][newj]));
                    if(newd<vis[newi][newj]){
                        vis[newi][newj]=newd;
                        q.push({newd,{newi,newj}});
                    }
                }
            }
        }
        return vis[rows-1][columns-1]!=INT_MAX?vis[rows-1][columns-1]:0;
    }
};
