class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int gaps = abs(nums[0] - nums[n - 1]) > 1;

        for (int i = 0; i < n - 1 && gaps < 2; i++) {
            if (abs(nums[i] - nums[i + 1]) > 1)
                gaps++;
        }

        if (gaps > 1)
            return -1;

        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        if (nums[(z + 1) % n] > 1)
            return min(z + 2, n - z);

        return min(z, n - z + 2);
    }
};