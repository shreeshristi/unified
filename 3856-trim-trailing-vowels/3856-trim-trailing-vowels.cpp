class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        int c=0,f=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='u'||s[i]=='o'){
                // s.remove(s[i]);/
                c=i;f=1;
            }else{
                break;
            }
        }
        if(f==0) return s;
        s.resize(c);
        return s;
        
    }
};