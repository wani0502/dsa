class Solution {
public:
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0) return grid[0][0];
        if(i<0||j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(grid,i-1,j,dp)+grid[i][j];
        int left=f(grid,i,j-1,dp)+grid[i][j];
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[i][j]=grid[0][0];
                else{
                    int up=1e9;
                    int left=1e9;

                    
                if(i>0) up=grid[i][j]+dp[i-1][j];
                if(j>0) left=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};