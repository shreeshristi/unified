class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=0, curans=0;
        vector<int> mpp(26, 0);
       
        while(r<s.size()){
            mpp[s[r]- 'A']++; 
            curans=max(curans,mpp[s[r]-'A']);
            while(r-l+1-curans>k){      //alpha different from max occuring
                mpp[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;   
        }
        return ans;
    }
};