class Solution {
public:
    // int lcs(int i,int j,string s,string t,vector<vector<int>>&dp){
    //     if(i<0||j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]) return dp[i][j]=1+lcs(i-1,j-1,s,t,dp);

    //     return dp[i][j]=max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
    // }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
       
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                   
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};