class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev=nums[0];
        int n=nums.size();
        int curi;
        int take;
        for(int i=1;i<n;i++){
            take=nums[i];
            if(i>1) take+=prev2;

            int nottake = 0+prev;

            curi=max(take,nottake);
            prev2=prev;
            prev=curi;
            
        }
        return prev;
        
    }
};