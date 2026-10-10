class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
           
            else if(s[i]==')'&&i+1<n&&  s[i+1]==')'){
                if(!st.empty()){
                    i++;
                    st.pop();
                }
                else{
                    ans+=1;
                    i++;
                }
            }
            else{
                if(!st.empty()){
                    ans+=1;st.pop();
                }
                
                else{
                    ans+=2;
                }

            }

        }
        ans=ans+st.size()*2;
        return ans;

        
    }
};