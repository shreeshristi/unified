class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1)
            return to_string(nums[0]);
        
        if (n == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string result = to_string(nums[0]) + "/(";
        
        for (int i = 1; i < n; i++) {
            result += to_string(nums[i]);
            if (i != n - 1)
                result += "/";
        }
        
        result += ")";
        
        return result;
    }
};