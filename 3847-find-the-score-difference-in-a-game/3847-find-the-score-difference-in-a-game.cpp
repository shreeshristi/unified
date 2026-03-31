class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int s1=0,s2=0;
        bool c1=true,c2=false;
        int active=0;
        for(int i=0;i<nums.size();i++){
            //odd pomits
            if(nums[i]%2==1){
                c1=!c1;
                c2=!c2;
            }
            if(i%6==5){
                c1=!c1;
                c2=!c2;
            }
            if(c1==true){
                s1+=nums[i];
            }else{
                s2+=nums[i];
            }
        }
        return s1-s2;;
        
    }
};