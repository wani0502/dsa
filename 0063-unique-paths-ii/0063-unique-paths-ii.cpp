class Solution {
public:
    int f(vector<vector<int>>& ob,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(ob[i][j]==1) return 0;
        if(i==0&&j==0) return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=f(ob,i-1,j,dp);
        int left=f(ob,i,j-1,dp);
        return dp[i][j]=up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(obstacleGrid,n-1,m-1,dp);
    }
};