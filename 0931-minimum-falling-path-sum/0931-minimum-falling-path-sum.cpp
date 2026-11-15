class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>> &matrix){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];
      
        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+f(i-1,j,dp,matrix);
        int ldg=matrix[i][j]+f(i-1,j-1,dp,matrix);
        int rdg=matrix[i][j]+f(i-1,j+1,dp,matrix);
        return dp[i][j]=min({up,ldg,rdg});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int ldg=matrix[i][j];
                if(j-1>=0) ldg+=dp[i-1][j-1];
                else ldg=1e9;
                int rdg=matrix[i][j];
                if(j+1<m) rdg+=dp[i-1][j+1];
                else rdg=1e9;
                dp[i][j]=min({up,rdg,ldg});
            }
        }
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};