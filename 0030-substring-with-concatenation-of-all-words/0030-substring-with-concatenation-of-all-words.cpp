class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        int l = s.size();

        vector<int> ans;
        if (l < n * m) return {};

        unordered_map<string, int> mpp;
        for (auto &w : words) {
            mpp[w]++;
        }

        // try all offsets
        for (int i = 0; i < m; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int j = i; j + m <= l; j += m) {
                string word = s.substr(j, m);

                if (mpp.find(word) != mpp.end()) {
                    window[word]++;
                    count++;

                    // shrink window if frequency exceeds
                    while (window[word] > mpp[word]) {
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }

                    if (count == n) {
                        ans.push_back(left);

                        // slide forward
                        string leftWord = s.substr(left, m);
                        window[leftWord]--;
                        left += m;
                        count--;
                    }
                } else {
                    // reset window
                    window.clear();
                    count = 0;
                    left = j + m;
                }
            }
        }

        return ans;
    }
};