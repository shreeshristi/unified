class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> mpp;
        int minwindow=INT_MAX,sindex=-1;
        for(int i=0;i<t.size();i++) mpp[t[i]]++;
        int count=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(mpp[s[r]]>0) count++;
            mpp[s[r]]--;

            while(count==t.size()){
                if(r-l+1<minwindow){
                    minwindow=r-l+1;
                    sindex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) count--;
                l++;
            }
            
        }
        if(sindex==-1) return "";
        return s.substr(sindex,minwindow);
        
    }
};