
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<long long> freq(100001, 0);
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            sum += d;
        }

        if (sum <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            long long take = min(k, freq[d]);
            freq[d] -= take;
            freq[d - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for (int d = 0; d <= 100000; d++)
            ans += 1LL * d * d * freq[d];

        return ans;
    }
};