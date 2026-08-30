class Solution {
public:
    // int f(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp){
    //     if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down=triangle[i][j]+f(triangle,i+1,j,dp);
    //     int dg=triangle[i][j]+f(triangle,i+1,j+1,dp);
    //     return dp[i][j]=min(down,dg);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else{
                    
                   int down=triangle[i][j]+dp[i+1][j];
                    int dg=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(down,dg);
                }
            }
        }
        return dp[0][0];
    }
};