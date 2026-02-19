class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int cur=1,prev=0,ans=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cur++;
            else{
                ans+=min(prev,cur);
                prev=cur;
                cur=1;
            }
        }
        ans+=min(prev,cur);
        return ans;

        
        
    }
};