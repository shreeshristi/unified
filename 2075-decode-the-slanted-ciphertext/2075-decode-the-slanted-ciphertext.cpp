class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (rows == 0) return "";

        int n = s.size();
        int cols = n / rows;

        // Step 1: Build matrix
        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = s[idx++];
            }
        }

        // Step 2: Traverse diagonals
        string ans = "";

        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;

            while (i < rows && j < cols) {
                ans.push_back(mat[i][j]);
                i++;
                j++;
            }
        }

        // Step 3: Remove trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};