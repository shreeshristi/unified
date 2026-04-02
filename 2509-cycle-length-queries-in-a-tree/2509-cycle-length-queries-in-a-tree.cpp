class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries){
            int cnt=1;
            int a=x[0],b=x[1];
            while(a!=b){
                if(a>b) a=a/2;
                else b=b/2;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;

    }
};