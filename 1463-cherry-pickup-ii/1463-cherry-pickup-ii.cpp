class Solution {
public:

    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int i,int j1,int j2){
        int n=grid.size(),m=grid[0].size();
        if(j1<0||j2<0||j1>m-1||j2>m-1) return INT_MIN;
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = -1e9;
        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int ans = curr + solve(grid,dp,i + 1, j1 + dj1, j2 + dj2);
                maxi = max(maxi, ans);
            }
        }
        // Store result
        return dp[i][j1][j2] = maxi;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid,dp,0,0,m-1);
        
    }
};