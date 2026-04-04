class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int maxx=INT_MIN, cnt=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,weight[i]);
            if(weight[i]<maxx){
                cnt++;
                maxx=INT_MIN;
            }
        }
        return cnt;
        
    }
};