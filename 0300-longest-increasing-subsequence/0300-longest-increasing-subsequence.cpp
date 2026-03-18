class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto m=lower_bound(temp.begin(),temp.end(), nums[i]);//lb return pointer not int so auto
                *m =nums[i];
            }
           
        }
        return temp.size();

        
    }
};