class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && vis[i][j] == 0) {

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    long long tempsum = 0;

                    while(!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        tempsum += grid[r][c];

                        for(int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if(nr >= 0 && nc >= 0 && nr < n && nc < m &&
                               grid[nr][nc] != 0 && vis[nr][nc] == 0) {
                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }

                    if(tempsum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};