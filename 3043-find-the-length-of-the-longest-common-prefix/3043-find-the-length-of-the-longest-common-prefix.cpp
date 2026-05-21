class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        unordered_set<int> pref;
        for(int i=0;i<n;i++){
            while(arr1[i]>0){
                pref.insert(arr1[i]);
                arr1[i]/=10;
            }
        }
        int ans=0;
        for(int i = 0; i < m; i++) {
            int num = arr2[i];
                while(num > 0) {
                    if(pref.find(num) != pref.end()) {
                        ans = max(ans, (int)to_string(num).size());
                    }
                    num /= 10;
                }
        }
        return ans;

        
    }
};