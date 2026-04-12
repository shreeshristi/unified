class Solution {
public:
    int dp[301][27];
    int dist(char a, char b) {
        if (a == '#') return 0; // free start
        int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
        int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int solve(string &word, int i, int other) {
        if (i == word.size()) return 0;
        if (dp[i][other] != -1) return dp[i][other];
        char curr = word[i];
        char prev = (i == 0 ? '#' : word[i - 1]);
        int useSame = dist(prev, curr) + solve(word, i + 1, other);
        char otherChar = (other == 26 ? '#' : 'A' + other);
        int nextOther = (prev == '#') ? 26 : (prev - 'A');
        int useOther = dist(otherChar, curr) + solve(word, i + 1, nextOther);

        return dp[i][other] = min(useSame, useOther);
    }


    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26); //26 letters+not select option
        
    }
};