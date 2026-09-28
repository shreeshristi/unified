class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                string temp;
                while (!st.empty() && st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for (char x : temp) {
                    st.push(x);
                }
            } 
            else st.push(c);
        }

        string ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};