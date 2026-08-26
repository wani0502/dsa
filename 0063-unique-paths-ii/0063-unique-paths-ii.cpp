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
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
 
    if (obstacleGrid[0][0] == 1) return 0;
    
    vector<int> prev(m,0);
    for(int i = 0; i <=n-1; i++){
        vector<int> curr(m,0);
        for(int j = 0; j <=m-1; j++){
           
            if(obstacleGrid[i][j] == 1) {
               curr[j] = 0;
            } 
            
            else if(i == 0 && j == 0) {
                curr[j] = 1;
            } 
          
            else {
                int up = 0;
                int left = 0;
                
                if(i > 0) up = prev[j];    
                if(j > 0) left = curr[j-1];  
                curr[j] = up + left;
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
};