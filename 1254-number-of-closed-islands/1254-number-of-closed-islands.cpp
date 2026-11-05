
class Solution {
public:

    bool dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Out of bounds means island touches boundary
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        // Water or already visited
        if (grid[i][j] == 1)
            return true;

        // Mark visited
        grid[i][j] = 1;

        bool closed = true;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (!dfs(nr, nc, grid, n, m))
                closed = false;
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid, n, m))
                        ans++;
                }
            }
        }

        return ans;
    }
};
