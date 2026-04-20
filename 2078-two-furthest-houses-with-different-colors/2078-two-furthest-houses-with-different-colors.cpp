class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int p=0,q=n-1;
        int val=0;
        for(int i=0;i<n;i++){
            if(colors[q]!=colors[i]){
                val=abs(q-i);
                break;
            }
        }

        for(int j=n-1;j>0;j--){
            if(colors[p]!=colors[j]){
                val=max(val,abs(p-j));
                break;
            }
        }

        return val;
        
        
    }
};