class Solution {
public:
    int minimumIndex(vector<int>& capacity, int item) {
        int n=capacity.size();
        int index=0, ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(capacity[i]>=item&& capacity[i]<ans){
                index=i; ans=capacity[i];
            }


        }
        if(ans!=INT_MAX)return index;
        return -1;
        
    }
};