class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>> & board){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if(nrow<n && nrow>=0&& ncol<m && ncol>=0 && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i]&&board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i]&&board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0]&& board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1]&& board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};