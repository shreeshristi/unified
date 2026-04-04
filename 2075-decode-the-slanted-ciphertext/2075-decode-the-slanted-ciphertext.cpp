class Solution {
public:
 

    void create_sen(int i, int j, string &ans, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // base condition
        if (i >= n || j >= m) return;

        ans.push_back(mat[i][j]);

        // move diagonally
        create_sen(i + 1, j + 1, ans, mat);
    }

    string decodeCiphertext(string s, int rows) {
        if (rows == 0) return "";

        int n = s.size();
        int cols = n / rows;

        // FIXED: proper initialization
        vector<vector<char>> mat(rows, vector<char>(cols));

        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = s[idx++];
            }
        }

        string ans = "";

        // Start from top row, each column
        for (int j = 0; j < cols; j++) {
            create_sen(0, j, ans, mat);
        }

        // remove trailing spaces
        int end = ans.size() - 1;
        while (end >= 0 && ans[end] == ' ') end--;

        return ans.substr(0, end + 1);
    }
};