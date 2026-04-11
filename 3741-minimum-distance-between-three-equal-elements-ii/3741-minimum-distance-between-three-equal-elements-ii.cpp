class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto &p : mpp) {
            auto &v = p.second;

            if (v.size() < 3) continue;

            //distance
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
        
    }
};